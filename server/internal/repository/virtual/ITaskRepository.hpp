#ifndef SOURCEDOUT_ITASKREPOSITORY_HPP
#define SOURCEDOUT_ITASKREPOSITORY_HPP

#include <iostream>
#include "../../entities/include/Task.hpp"

class ITaskRepository {
    virtual Task getTaskById(size_t id) = 0;

    virtual void updateTask(Task task) = 0;

    virtual size_t storeTask(Task task) = 0;

    virtual void deleteTask(Task task) = 0;

    virtual void deleteTaskById(size_t task_id) = 0;
};

#endif //SOURCEDOUT_ITASKREPOSITORY_HPP
