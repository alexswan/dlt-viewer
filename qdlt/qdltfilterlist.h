/**
 * @licence app begin@
 * Copyright (C) 2011-2012  BMW AG
 *
 * This file is part of GENIVI Project Dlt Viewer.
 *
 * Contributions are licensed to the GENIVI Alliance under one or more
 * Contribution License Agreements.
 *
 * \copyright
 * This Source Code Form is subject to the terms of the
 * Mozilla Public License, v. 2.0. If a  copy of the MPL was not distributed with
 * this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * \author Alexander Wenzel <alexander.aw.wenzel@bmw.de> 2011-2012
 *
 * \file qdlt.h
 * For further information see http://www.genivi.org/.
 * @licence end@
 */

#ifndef QDLT_FILTER_LIST_H
#define QDLT_FILTER_LIST_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QDateTime>
#include <QColor>
#include <QMutex>
#include <time.h>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include "export_rules.h"


class QDLT_EXPORT QDltFilterList
{
public:

    //! The constructor.
    /*!
    */
    QDltFilterList();

    //! The destructor.
    /*!
    */
    ~QDltFilterList();

    //! Copy operator.
    QDltFilterList& operator= (QDltFilterList const& _filterList);

    //! Delete all filters and markers.
    /*!
      This includes all positive and negative filters and markers.
    */
    void clearFilter();

    //! Add a filter to the filter list.
    /*!
      \param filter the filter configuration
    */
    void addFilter(QDltFilter &filter);

    //! Check if message will be marked.
    /*!
      Colours used are:
      1 = green
      2 = red
      3 = yellow
      4 = blue
      5 = light grey
      6 = dark grey
      \param msg The messages to be marked
      \return 0 if message will not be marked, colour if message will be marked
    */
    QColor checkMarker(QDltMsg &msg);

    //! Check if message matches the filter.
    /*!
      \param msg The message to be checked
      \return true if message wil be displayed, false if message will be filtered out
    */
    bool checkFilter(QDltMsg &msg);

    bool SaveFilter(QString filename);
    bool LoadFilter(QString filename,bool replace);

    //! List of filters.
    QList<QDltFilter> filters;

protected:
private:


};

#endif // QDLT_FILTER_LIST_H
