///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

#ifndef MAPIO_H
#define MAPIO_H

#include "abstractmap.h"

/// This class adds Cities and Streeds to a Map.
class MapIo
{
public:
    
    /// virtual Destructor
    virtual ~MapIo();
    
    /// this method adds Cities and Streets to the provided Map.
    virtual void fillMap(AbstractMap &map) = 0;
};

#endif // MAPIO_H
