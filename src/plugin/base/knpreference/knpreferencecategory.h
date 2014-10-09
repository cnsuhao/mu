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
#ifndef KNPREFERENCECATEGORY_H
#define KNPREFERENCECATEGORY_H

#include <QList>
#include <QPixmap>
#include <QWidget>

class QBoxLayout;
class QTimeLine;
class KNPreferenceTitle;
class KNPreferenceCategoryList;
class KNPreferenceCategory : public QWidget
{
    Q_OBJECT
public:
    explicit KNPreferenceCategory(QWidget *parent = 0);
    int currentIndex() const;

signals:
    void requireHidePreference();

public slots:
    void addCategory(const QString &title,
                     const QPixmap &icon,
                     const QPixmap &headerIcon);
    void setCurrentIndex(const int &index);
    void retranslate();

protected:
    void showEvent(QShowEvent *event);
    void paintEvent(QPaintEvent *event);

private slots:
    void onActionIndexChanged(const int &index);

private:
    void syncTitle();
    QColor m_backgroundColor=QColor(42,42,42),
           m_borderColor=QColor(255,255,255,67);
    int m_listWidth=250, m_shadowWidth=15, m_highlightHeight=64;
    QLinearGradient m_highlightGradient;
    QBoxLayout *m_layout;
    QString m_generalText;
    QList<QPixmap> m_headerIcons;
    KNPreferenceTitle *m_title;
    KNPreferenceCategoryList *m_categoryList;
};

#endif // KNPREFERENCECATEGORY_H