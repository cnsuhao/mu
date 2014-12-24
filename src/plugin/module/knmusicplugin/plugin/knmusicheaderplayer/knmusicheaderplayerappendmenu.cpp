/*
 * Copyright (C) Kreogist Dev Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */
#include <QSignalMapper>

#include "knlocalemanager.h"

#include "knmusicheaderplayerappendmenu.h"

KNMusicHeaderPlayerAppendMenu::KNMusicHeaderPlayerAppendMenu(QWidget *parent) :
    KNSAOSubMenu(parent)
{
    //Initial the trigger.
    m_actionTrigger=new QSignalMapper(this);
    connect(m_actionTrigger, SIGNAL(mapped(int)),
            this, SIGNAL(requireDoAction(int)));
    //Initial the menu and actions.
    initialSubMenus();
    initialActions();

    //Link retranslated signal.
    connect(KNLocaleManager::instance(), &KNLocaleManager::requireRetranslate,
            this, &KNMusicHeaderPlayerAppendMenu::retranslate);
    //Retranslate the menu.
    retranslate();
}

KNMusicHeaderPlayerAppendMenu::~KNMusicHeaderPlayerAppendMenu()
{
    ;
}

void KNMusicHeaderPlayerAppendMenu::retranslate()
{
    //Set the sub menu title.
    m_subMenus[SubMenuShowIn]->menuAction()->setText(tr("Show in"));
    //Set the action title.
#ifdef Q_OS_WIN32
    m_menuActions[AppendShowInGraphicShell]->setText(tr("Show in Explorer"));
#endif
#ifdef Q_OS_MAC
    m_menuActions[AppendShowInGraphicShell]->setText(tr("Show in Finder"));
#endif
#ifdef Q_OS_LINUX
    m_menuActions[AppendShowInGraphicShell]->setText(tr("Show the contains folder"));
#endif
    m_menuActions[AppendLocateSong]->setText(tr("Locate the current song"));
    m_menuActions[AppendShowInSongs]->setText(tr("Show in songs"));
    m_menuActions[AppendShowInArtists]->setText(tr("Show in artists"));
    m_menuActions[AppendShowInAlbums]->setText(tr("Show in albums"));
    m_menuActions[AppendShowInGenres]->setText(tr("Show in genres"));
}

inline void KNMusicHeaderPlayerAppendMenu::initialSubMenus()
{
    //Generate the sub menus.
    for(int i=0; i<SubMenuCount; i++)
    {
        m_subMenus[i]=new KNSAOSubMenu(this);
    }
    //Set the icons.
    m_subMenus[SubMenuShowIn]->menuAction()->setIcon(
                QIcon(":/plugin/music/player/menuicons/locate_original.png"));
}

inline void KNMusicHeaderPlayerAppendMenu::initialActions()
{
    //Generate the actions.
    for(int i=0; i<MenuActionsCount; i++)
    {
        m_menuActions[i]=new QAction(this);
        //Link to the action trigger.
        connect(m_menuActions[i], SIGNAL(triggered()),
                m_actionTrigger, SLOT(map()));
        m_actionTrigger->setMapping(m_menuActions[i], i);
    }

    m_menuActions[AppendShowInGraphicShell]->setIcon(
                QIcon(":/plugin/music/player/menuicons/showInGraphicsShell.png"));
    addAction(m_menuActions[AppendShowInGraphicShell]);

    //Add actions to menu.
    m_menuActions[AppendLocateSong]->setIcon(
                QIcon(":/plugin/music/player/menuicons/locate_original.png"));
    m_subMenus[SubMenuShowIn]->addAction(m_menuActions[AppendLocateSong]);
    m_menuActions[AppendShowInSongs]->setIcon(
                QIcon(":/plugin/music/player/menuicons/locate_songs.png"));
    m_subMenus[SubMenuShowIn]->addAction(m_menuActions[AppendShowInSongs]);
    m_menuActions[AppendShowInArtists]->setIcon(
                QIcon(":/plugin/music/player/menuicons/locate_artists.png"));
    m_subMenus[SubMenuShowIn]->addAction(m_menuActions[AppendShowInArtists]);
    m_menuActions[AppendShowInAlbums]->setIcon(
                QIcon(":/plugin/music/player/menuicons/locate_albums.png"));
    m_subMenus[SubMenuShowIn]->addAction(m_menuActions[AppendShowInAlbums]);
    m_menuActions[AppendShowInGenres]->setIcon(
                QIcon(":/plugin/music/player/menuicons/locate_genres.png"));
    m_subMenus[SubMenuShowIn]->addAction(m_menuActions[AppendShowInGenres]);

    addMenu(m_subMenus[SubMenuShowIn]);
}

