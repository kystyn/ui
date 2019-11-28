/*
 * Copyright (C) 2008 Apple Inc. All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */


#ifndef SVGSMILElement_h
#define SVGSMILElement_h
#if ENABLE(SVG_ANIMATION)

#include "SVGElement.h"
#include "SMILTime.h"
#include <wtf/HashMap.h>

namespace WebCore {
    
    class ConditionEventListener;
    class SMILTimeContainer;

    // This class implements SMIL interval timing model as needed for SVG animation.
    class SVGSMILElement : public SVGElement {
    public:
        SVGSMILElement(const QualifiedName&, Document*);
        virtual ~SVGSMILElement();
        
        static bool isSMILElement(Node* node);
        
        virtual void parseMappedAttribute(MappedAttribute*);
        virtual void attributeChanged(Attribute*, bool preserveDecls);
        virtual void insertedIntoDocument();
        virtual void removedFromDocument();
        virtual void finishParsingChildren();
                
        SMILTimeContainer* timeContainer() const { return m_timeContainer.get(); }

        SVGElement* targetElement() const;
        String attributeName() const;
        
        void beginByLinkActivation();

        enum Restart { RestartAlways, RestartWhenNotActive, RestartNever };
        Restart restart() const;
        
        enum FillMode { FillRemove, FillFreeze };
        FillMode fill() const;
        
        String xlinkHref() const;
        
        SMILTime dur() const;
        SMILTime repeatDur() const;
        SMILTime repeatCount() const;
        SMILTime maxValue() const;
        SMILTime minValue() const;
        
        SMILTime elapsed() const; 
        
        SMILTime intervalBegin() const { return m_intervalBegin; }
        SMILTime intervalEnd() const { return m_intervalEnd; }
        SMILTime previousIntervalBegin() const { return m_previousIntervalBegin; }
        SMILTime simpleDuration() const;
        
        void progress(SMILTime elapsed, SVGSMILElement* resultsElement);
        SMILTime nextProgressTime() const;
        
        static SMILTime parseClockValue(const String&);
        static SMILTime parseOffsetValue(const String&);
        
        bool isContributing(SMILTime elapsed) const;
        bool isInactive() const;
        bool isFrozen() const;
        
        unsigned documentOrderIndex() const { return m_documentOrderIndex; }
        void setDocumentOrderIndex(unsigned index) { m_documentOrderIndex = index; }
        
        virtual bool isAdditive() const = 0;
        virtual void resetToBaseValue(const String&) = 0;
        virtual void applyResultsToTarget() = 0;
        
protected:
        void addBeginTime(SMILTime time);
        void addEndTime(SMILTime time);
        
private:
        virtual void startedActiveInterval() = 0;
        virtual void updateAnimation(float percent, unsigned repeat, SVGSMILElement* resultElement) = 0;
        virtual void endedActiveInterval() = 0;
        
        enum BeginOrEnd { Begin, End };
        SMILTime findInstanceTime(BeginOrEnd beginOrEnd, SMILTime minimumTime, bool equalsMinimumOK) const;
        void resolveFirstInterval();
        void resolveNextInterval();
        void resolveInterval(bool first, SMILTime& beginResult, SMILTime& endResult) const;
        SMILTime resolveActiveEnd(SMILTime resolvedBegin, SMILTime resolvedEnd) const;
        SMILTime repeatingDuration() const;
        void checkRestart(SMILTime elapsed);
        void beginListChanged();
        void endListChanged();
        void reschedule();

        // This represents conditions on elements begin or end list that need to be resolved on runtime
        // for example <animate begin="otherElement.begin + 8s; button.click" ... />
        struct Condition {
            enum Type { EventBase, Syncbase, AccessKey };
            Condition(Type, BeginOrEnd beginOrEnd, const String& baseID, const String& name, SMILTime offset, int repeats = -1);
            Type m_type;
            BeginOrEnd m_beginOrEnd;
            String m_baseID;
            String m_name;
            SMILTime m_offset;
            int m_repeats;
            RefPtr<Element> m_syncbase;
            RefPtr<ConditionEventListener> m_eventListener;
        };
        bool parseCondition(const String&, BeginOrEnd beginOrEnd);
        void parseBeginOrEnd(const String&, BeginOrEnd beginOrEnd);
        Element* eventBaseFor(const Condition&) const;

        void connectConditions();
        void disconnectConditions();
        
        // Event base timing
        void handleConditionEvent(Event*, Condition*);
        
        // Syncbase timing
        enum NewOrExistingInterval { NewInterval, ExistingInterval }; 
        void notifyDependentsIntervalChanged(NewOrExistingInterval);
        void createInstanceTimesFromSyncbase(SVGSMILElement* syncbase, NewOrExistingInterval);
        void addTimeDependent(SVGSMILElement*);
        void removeTimeDependent(SVGSMILElement*);
        
        enum ActiveState { Inactive, Active, Frozen };
        ActiveState determineActiveState(SMILTime elapsed) const;
        float calculateAnimationPercentAndRepeat(SMILTime elapsed, unsigned& repeat) const;
        SMILTime calculateNextProgressTime(SMILTime elapsed) const;
        
        Vector<Condition> m_conditions;
        bool m_conditionsConnected;
        bool m_hasEndEventConditions;     
        
        typedef HashSet<SVGSMILElement*> TimeDependentSet;
        TimeDependentSet m_timeDependents;
        
        // Instance time lists
        Vector<SMILTime> m_beginTimes;
        Vector<SMILTime> m_endTimes;
        
        // This is the upcoming or current interval
        SMILTime m_intervalBegin;
        SMILTime m_intervalEnd;
        
        SMILTime m_previousIntervalBegin;
        
        bool m_isWaitingForFirstInterval;
    
        ActiveState m_activeState;
        float m_lastPercent;
        unsigned m_lastRepeat;
        
        SMILTime m_nextProgressTime;
        
        RefPtr<SMILTimeContainer> m_timeContainer;
        unsigned m_documentOrderIndex;

        mutable SMILTime m_cachedDur;
        mutable SMILTime m_cachedRepeatDur;
        mutable SMILTime m_cachedRepeatCount;
        mutable SMILTime m_cachedMin;
        mutable SMILTime m_cachedMax;
        
        friend class ConditionEventListener;
    };

}

#endif
#endif

