#ifndef JLCOMPRESSFOLDER_H_
#define JLCOMPRESSFOLDER_H_

/*
Copyright (C) 2010 Roberto Pompermaier
Copyright (C) 2005-2014 Sergey A. Tachenov

This file is part of QuaZIP.

QuaZIP is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

QuaZIP is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with QuaZIP.  If not, see <http://www.gnu.org/licenses/>.

See COPYING file for the full LGPL text.

Original ZIP package is copyrighted by Gilles Vollant and contributors,
see quazip/(un)zip.h files for details. Basically it's the zlib license.
*/

#include "quazip.h"
#include "quazipfile.h"
#include "quazipfileinfo.h"
#include <QString>
#include <QDir>
#include <QFileInfo>
#include <QFile>
#include <QObject>
/// Utility class for typical operations.
/**
  This class contains a number of useful static functions to perform
  simple operations, such as mass ZIP packing or extraction.
  */


class QUAZIP_EXPORT JlCompress : public QObject{
    Q_OBJECT
public:
    explicit JlCompress(QObject* parent = 0);
    qint64 curWriteByte;
    qint64 dirTotalByte;
    qreal curPercent;

signals:
    void compressStart();
    void compressFinish();
    void compressProgress(int progress);
    void comprssError();
private:
    void progressCalq();
    bool copyData(QIODevice &inFile, QIODevice &outFile);
    qint64 getDirSize(QString dirPath);
    /// Compress a single file.
    /**
      \param zip Opened zip to compress the file to.
      \param fileName The full path to the source file.
      \param fileDest The full name of the file inside the archive.
      \return true if success, false otherwise.
      */
    bool compressFile(QuaZip* zip, QString fileName, QString fileDest);
    /// Compress a subdirectory.
    /**
      \param parentZip Opened zip containing the parent directory.
      \param dir The full path to the directory to pack.
      \param parentDir The full path to the directory corresponding to
      the root of the ZIP.
      \param recursive Whether to pack sub-directories as well or only
      files.
      \return true if success, false otherwise.
      */
    bool compressSubDir(QuaZip* parentZip, QString dir, QString parentDir, bool recursive = true);
    /// Extract a single file.
    /**
      \param zip The opened zip archive to extract from.
      \param fileName The full name of the file to extract.
      \param fileDest The full path to the destination file.
      \return true if success, false otherwise.
      */
    bool extractFile(QuaZip* zip, QString fileName, QString fileDest);
    /// Remove some files.
    /**
      \param listFile The list of files to remove.
      \return true if success, false otherwise.
      */
    bool removeFile(QStringList listFile);

public:
    /// Compress a single file.
    /**
      \param fileCompressed The name of the archive.
      \param file The file to compress.
      \return true if success, false otherwise.
      */
    bool compressFile(QString fileCompressed, QString file);
    /// Compress a list of files.
    /**
      \param fileCompressed The name of the archive.
      \param files The file list to compress.
      \return true if success, false otherwise.
      */
    bool compressFiles(QString fileCompressed, QStringList files);
    /// Compress a whole directory.
    /**
      \param fileCompressed The name of the archive.
      \param dir The directory to compress.
      \param recursive Whether to pack the subdirectories as well, or
      just regular files.
      \return true if success, false otherwise.
      */
    bool compressDir(QString fileCompressed, QString dir = QString(), bool recursive = true);
public slots:
    void slt_compressDir(QString fileCompressed, QString dir = QString());
public:
    /// Extract a single file.
    /**
      \param fileCompressed The name of the archive.
      \param fileName The file to extract.
      \param fileDest The destination file, assumed to be identical to
      \a file if left empty.
      \return The list of the full paths of the files extracted, empty on failure.
      */
    QString extractFile(QString fileCompressed, QString fileName, QString fileDest = QString());
    /// Extract a list of files.
    /**
      \param fileCompressed The name of the archive.
      \param files The file list to extract.
      \param dir The directory to put the files to, the current
      directory if left empty.
      \return The list of the full paths of the files extracted, empty on failure.
      */
    QStringList extractFiles(QString fileCompressed, QStringList files, QString dir = QString());
    /// Extract a whole archive.
    /**
      \param fileCompressed The name of the archive.
      \param dir The directory to extract to, the current directory if
      left empty.
      \return The list of the full paths of the files extracted, empty on failure.
      */
    QStringList extractDir(QString fileCompressed, QString dir = QString());
    /// Get the file list.
    /**
      \return The list of the files in the archive, or, more precisely, the
      list of the entries, including both files and directories if they
      are present separately.
      */
    QStringList getFileList(QString fileCompressed);
};

#endif /* JLCOMPRESSFOLDER_H_ */
