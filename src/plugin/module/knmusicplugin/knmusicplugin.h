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
#ifndef KNMUSICPLUGIN_H
#define KNMUSICPLUGIN_H

#include "knabstractmusicplugin.h"

class QBoxLayout;
class QSignalMapper;
class KNCategoryTabWidget;
class KNPreferenceWidgetsPanel;
class KNConnectionHandler;
class KNMouseDetectHeader;
class KNMusicTab;
class KNMusicBackend;
class KNMusicGlobal;
class KNMusicParser;
class KNMusicSearchBase;
class KNMusicDetailDialogBase;
class KNMusicDetailTooltipBase;
class KNMusicHeaderPlayerBase;
class KNMusicHeaderLyricsBase;
class KNMusicNowPlayingBase;
class KNMusicLibraryBase;
class KNMusicPlaylistManagerBase;
class KNMusicSoloMenuBase;
class KNMusicMultiMenuBase;
class KNMusicPlugin : public KNAbstractMusicPlugin
{
    Q_OBJECT
public:
    explicit KNMusicPlugin(QObject *parent = 0);
    ~KNMusicPlugin();
    QString caption();
    QPixmap icon();
    QPixmap headerIcon();
    QPixmap preferenceIcon();
    QWidget *centralWidget();
    QWidget *headerWidget();
    KNPreferenceWidgetsPanel *preferencePanelWidget();

    void setPlatformExtras(KNPlatformExtras *plugin);
    void loadSearch(KNMusicSearchBase *plugin);
    void loadDetailTooptip(KNMusicDetailTooltipBase *plugin);
    void loadBackend(KNMusicBackend *plugin);
    void loadDetailInfo(KNMusicDetailDialogBase *plugin);
    void loadHeaderPlayer(KNMusicHeaderPlayerBase *plugin);
    void loadHeaderLyrics(KNMusicHeaderLyricsBase *plugin);
    void loadNowPlaying(KNMusicNowPlayingBase *plugin);
    void loadLibrary(KNMusicLibraryBase *plugin);
    void loadPlaylistManager(KNMusicPlaylistManagerBase *plugin);

signals:

public slots:
    void onArgumentsAvailable(const QStringList &data);
    void retranslate();
    void enablePlatformExtras();
    void disablePlatformExtras();

protected slots:
    int addMusicCategory(const QPixmap &icon,
                         const QString &caption,
                         QWidget *widget);
    virtual void addLeftHeaderWidget(QWidget *widget,
                                     int stretch=0,
                                     Qt::Alignment alignment=0);
    virtual void addRightHeaderWidget(QWidget *widget,
                                      int stretch=0,
                                      Qt::Alignment alignment=0);

private slots:
    void onActionShowTab(const int &tabIndex);

private:
    inline void initialInfrastructure();
    inline void initialParser();
    void initialSoloMenu(KNMusicSoloMenuBase *soloMenu);
    void initialMultiMenu(KNMusicMultiMenuBase *multiMenu);
    void addMusicTab(KNMusicTab *musicTab);
    void startThreads();
    QLinkedList<QObject *> m_pluginList;
    struct MusicTabItem
    {
        int index;
        KNMusicTab *tab;
    };
    QLinkedList<MusicTabItem> m_tabList;
    QString m_caption;
    KNCategoryTabWidget *m_centralWidget=nullptr;
    KNMouseDetectHeader *m_headerWidget=nullptr;
    KNPreferenceWidgetsPanel *m_preferencePanel;
    QBoxLayout *m_headerLeftLayout, *m_headerRightLayout;
    QThread m_parserThread, m_backendThread;
    QSignalMapper *m_tabSwitchMapper;
    KNMusicGlobal *m_musicGlobal;

    KNMusicDetailDialogBase *m_detailDialog=nullptr;
    KNMusicBackend *m_backend=nullptr;
    KNMusicNowPlayingBase *m_nowPlaying=nullptr;
    KNMusicHeaderPlayerBase *m_headerPlayer=nullptr;
    KNPlatformExtras *m_platformExtras=nullptr;
    KNConnectionHandler *m_extraHandler=nullptr;
};

#endif // KNMUSICPLUGIN_H
