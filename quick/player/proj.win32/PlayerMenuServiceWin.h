
#ifndef __PLAYER_MENU_SERVICE_WIN_H_
#define __PLAYER_MENU_SERVICE_WIN_H_

#include <string>
#include <unordered_map>

#include "cocos2d.h"
#include "stdafx.h"
#include "PlayerMenuServiceProtocol.h"

PLAYER_NS_BEGIN

class PlayerMenuItemWin : public PlayerMenuItem
{
public:
    static PlayerMenuItemWin *create(const std::string &menuId, const std::string &title);
    virtual ~PlayerMenuItemWin();

    virtual void setTitle(const std::string &title);
    virtual void setEnabled(bool enabled);
    virtual void setChecked(bool checked);
    virtual void setShortcut(const std::string &shortcut);

protected:
    PlayerMenuItemWin();

    PlayerMenuItemWin *_parent;
    UINT _commandId;
    HMENU _hmenu;
    cocos2d::Vector<PlayerMenuItemWin*> _children;

    friend class PlayerMenuServiceWin;
};

class PlayerMenuServiceWin : public PlayerMenuServiceProtocol
{
public:
    PlayerMenuServiceWin(HWND hwnd);
    virtual ~PlayerMenuServiceWin();

    virtual PlayerMenuItem *addItem(const std::string &menuId,
                                    const std::string &title,
                                    const std::string &parentId,
                                    int order = MAX_ORDER);
    virtual PlayerMenuItem *addItem(const std::string &menuId,
                                    const std::string &title);
    virtual PlayerMenuItem *getItem(const std::string &menuId);
    virtual bool removeItem(const std::string &menuId);

private:
    static UINT _newCommandId;

    HWND _hwnd;
    PlayerMenuItemWin _root;
    std::unordered_map<std::string, PlayerMenuItemWin*> _items;
    std::unordered_map<UINT, std::string> _commandId2menuId;

    bool removeItemInternal(const std::string &menuId, bool isUpdateChildrenOrder);
    void updateChildrenOrder(PlayerMenuItemWin *parent);
};

PLAYER_NS_END

#endif // __PLAYER_MENU_SERVICE_WIN_H_
