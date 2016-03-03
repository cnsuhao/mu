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
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */
#ifndef KNACCOUNTLOGINPANEL_H
#define KNACCOUNTLOGINPANEL_H

#include <QWidget>

class QLabel;
class KNLabelLineEdit;
class KNOpacityAnimeButton;
/*!
 * \brief The KNAccountLoginPanel class provides a widget to login to Kreogist
 * Account. The widget style is SAO style, notice this widget could only be used
 * in notification center.
 */
class KNAccountLoginPanel : public QWidget
{
    Q_OBJECT
public:
    /*!
     * \brief Construct a KNAccountPanel widget.
     * \param parent The parent widget.
     */
    explicit KNAccountLoginPanel(QWidget *parent = 0);

signals:

public slots:

protected:
    /*!
     * \brief Reimplemented from QWidget::hideEvent().
     */
    void hideEvent(QHideEvent *event) Q_DECL_OVERRIDE;

private slots:
    void retranslate();

private:
    inline KNOpacityAnimeButton *generateButton(const QString &iconPath);
    QLabel *m_title, *m_subTitle;
    KNLabelLineEdit *m_username, *m_password;
    KNOpacityAnimeButton *m_login, *m_others;
};

#endif // KNACCOUNTLOGINPANEL_H
