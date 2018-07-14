/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/deathmatch/logic/CObjectManager.h
 *  PURPOSE:     Object entity manager class
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

#pragma once

#include "CObject.h"
#include <list>

using std::list;

class CObject;
typedef CFastList<CObject*> CObjectListType;

class CObjectManager
{
    friend class CObject;

public:
    CObjectManager(void);
    ~CObjectManager(void);

    CObject* Create(CElement* pParent, CXMLNode* pNode, bool bIsLowLod);
    CObject* CreateFromXML(CElement* pParent, CXMLNode& Node, CEvents* pEvents, bool bIsLowLod);
    void     DeleteAll(void);

    unsigned int Count(void) { return static_cast<unsigned int>(m_List.size()); };
    bool         Exists(CObject* pObject);

    CObjectListType::const_iterator IterBegin(void) const { return m_List.begin(); };
    CObjectListType::const_iterator IterEnd(void) const { return m_List.end(); };

    static bool IsValidModel(unsigned long ulObjectModel);
    static bool IsBreakableModel(unsigned long ulObjectModel);

private:
    void AddToList(CObject* pObject) { m_List.push_back(pObject); };
    void RemoveFromList(CObject* pObject);

    CObjectListType m_List;
};
