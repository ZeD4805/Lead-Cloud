//
// Created by Asus on 04/11/2021.
//

#include "JobPriorityList.h"

void JobPriorityList::addJob(VisualJob* job) {
    JobListEntity** list;

    switch (job->priorityLevel) {
        case Alarm:
            list = &alarmListHead;
            break;
        case Raised:
            list = &raisedListHead;
            break;
        default: //Base
            list = &baseListHead;
            break;
    }

    addJobToList(job, list);
}

void JobPriorityList::addJobToList(VisualJob* job, JobListEntity** list){
    if(*list == nullptr){
        *list = new JobListEntity(*job);
        return;
    }

    JobListEntity** listIteration = list;

    while ((*listIteration)->next != nullptr){
        *listIteration = (*listIteration)->next;
    }

    (*listIteration)->next = new JobListEntity(*job);
}

VisualJob* JobPriorityList::removeJob(string ID) {

}

VisualJob* JobPriorityList::removeJob(string ID, PriorityLevel priority) {
    JobListEntity* list;

    switch (priority) {
        case Alarm:
            list = alarmListHead;
            break;
        case Raised:
            list = raisedListHead;
            break;
        case Base:
            list = baseListHead;
            break;
    }

    VisualJob* visualJob = nullptr;

    while (list != nullptr && list->job->ID != ID)
        list = list->next;

    if(list != nullptr){
        visualJob = list->job;
    }

    return visualJob;
}

VisualJob* JobPriorityList::removeJobFromList(string ID, JobListEntity** list){
    VisualJob* visualJob = nullptr;

    while (list != nullptr && list->job->ID != ID)
        list = list->next;

    if(list != nullptr){
        visualJob = list->job;
    }

    return visualJob;
}

VisualJob* JobPriorityList::popJob() {
    VisualJob* job;

    if(alarmListHead != nullptr){
        job = alarmListHead->job;
        alarmListHead = alarmListHead->next;

        return job;
    }
    else if (raisedListHead != nullptr){
        job = raisedListHead->job;
        raisedListHead = raisedListHead->next;

        return job;
    }
    else if (baseListHead != nullptr){
        job = baseListHead->job;
        baseListHead = baseListHead->next;

        return job;
    }
    else{ //no job available
        return &idleJob;
    }

}
