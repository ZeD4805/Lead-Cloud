//
// Created by Asus on 04/11/2021.
//

#ifndef LEAD_CLOUD_JOBPRIORITYLIST_H
#define LEAD_CLOUD_JOBPRIORITYLIST_H

#include "../VisualJobs/VisualJob.h"

class JobListEntity {
public:
    VisualJob *job;
    JobListEntity *next;

    JobListEntity(VisualJob* j) : job(j) {};

};

class JobPriorityList {
    JobListEntity* alarmListHead, *raisedListHead, *baseListHead;

    VisualJob idleJob;

    void addJob(VisualJob *job);

    void addJobToList(VisualJob *job, JobListEntity **list);

    VisualJob* removeJob(string ID);

    VisualJob* removeJob(string ID, PriorityLevel priority);

    VisualJob* removeJobFromList(string ID, JobListEntity** list);

    VisualJob* popJob();


};


#endif //LEAD_CLOUD_JOBPRIORITYLIST_H
