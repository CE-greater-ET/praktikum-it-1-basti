///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

#include "dijkstra.h"

#include <QDebug>

// This structure shall be used by the Dijkstra algorithm
class Tuppel
{
public:
    City* city;
    double distance;
    Street* shortestWay;
};


// The name of the variables is based on the Info I lecture notes.

QVector<Street*> Dijkstra::search(const AbstractMap &map, QString start, QString target)
{
    // Getting Pointer to start and target
    City* startPointer = map.findCity(start);
    City* targetPointer = map.findCity(target);
    if (startPointer == nullptr || targetPointer == nullptr)
    {
        qDebug() << "Dijkstra: Cities not found";

        // return an emply list
        QVector<Street*> l;
        return l;
    }

    // Defining Sets
    QVector<Tuppel> green;
    QVector<Tuppel> yellow;

    Tuppel temp = {startPointer, 0, nullptr};
    yellow.push_back(temp);

    // Starting Algorithm
    while (yellow.empty() == false)
    {
        // Finding Edge with smallest distance
        Tuppel edgeToProcessData;
        QVector<Tuppel>::iterator edgeToProcess = yellow.begin();
        for (QVector<Tuppel>::iterator it = yellow.begin(); it != yellow.end(); it++)
        {
            if ((*it).distance < (*edgeToProcess).distance)
            {
                edgeToProcess = it;
            }
        }
        edgeToProcessData = *edgeToProcess;
        green.push_back(*edgeToProcess);
        yellow.erase(edgeToProcess);

        // Getting list of all Succesors
        QVector<Street*> streets = map.getStreetList(edgeToProcessData.city);
        QVector<Tuppel> successorList;
        for (QVector<Street*>::const_iterator it = streets.begin(); it != streets.end(); it++)
        {
            // save all necessary data for the algorithm
            temp.city = map.getOppositeCity(*it, edgeToProcessData.city);
            temp.distance = map.getLength(*it);
            temp.shortestWay = *it;
            successorList.push_back(temp);
        }
        // for every Succesor
        for (QVector<Tuppel>::const_iterator successor = successorList.begin(); successor != successorList.end(); successor++)
        {
            // Test if City was already visited
            bool found = false;
            for (QVector<Tuppel>::iterator it = green.begin(); it != green.end(); it++)
            {
                // City already visited
                if ((*successor).city == (*it).city)
                {
                    found = true;
                    // Check if new way is shorter
                    if (edgeToProcessData.distance + (*successor).distance < (*it).distance)
                    {
                        // Save the new shortest way
                        (*it).distance = edgeToProcessData.distance + (*successor).distance;
                        (*it).shortestWay = (*successor).shortestWay;
                    }
                }
            }
            for (QVector<Tuppel>::iterator it = yellow.begin(); it != yellow.end(); it++)
            {
                // City already visited
                if ((*successor).city == (*it).city)
                {
                    found = true;
                    // Check if new way is shorter
                    if (edgeToProcessData.distance + (*successor).distance < (*it).distance)
                    {
                        // Save the new shortest way
                        (*it).distance = edgeToProcessData.distance + (*successor).distance;
                        (*it).shortestWay = (*successor).shortestWay;
                    }
                }
            }

            // if new town
            if (found == false)
            {
                temp.city = (*successor).city;
                temp.distance = edgeToProcessData.distance + (*successor).distance;
                temp.shortestWay = (*successor).shortestWay;
                yellow.push_back(temp);
            }
        }
    }

    // Building List with shortest Path
    QVector<Street*> shortestPath;
    City* currentEdge = nullptr;
    for (QVector<Tuppel>::const_iterator it = green.begin(); it != green.end(); it++)
    {
        if ((*it).city == targetPointer)
        {
            shortestPath.insert(shortestPath.begin(), (*it).shortestWay);
            currentEdge = map.getOppositeCity((*it).shortestWay,(*it).city);
        }
    }
    // No connection to the target
    if (currentEdge == nullptr)
    {
        qDebug() << "Dijkstra: No Connection beetween the targets";
        QVector<Street*> l;
        return l;
    }
    while (currentEdge != startPointer)
    {
        for (QVector<Tuppel>::const_iterator it = green.begin(); it != green.end(); it++)
        {
            if ((*it).city == currentEdge)
            {
                shortestPath.insert(shortestPath.begin(), (*it).shortestWay);
                currentEdge = map.getOppositeCity((*it).shortestWay, (*it).city);
            }
        }
    }
    return shortestPath;
}

