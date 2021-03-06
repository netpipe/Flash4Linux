/*
 *  FSSetBackgroundColor.cpp
 *  Transform SWF
 *
 *  Created by smackay on Tue Feb 18 2003.
 *  Copyright (c) 2001-2003 Flagstone Software Ltd. All rights reserved.
 *
 *  This file contains Original Code and/or Modifications of Original Code as defined in
 *  and that are subject to the Flagstone Software Source License Version 1.0 (the
 *  'License'). You may not use this file except in compliance with the License. Please
 *  obtain a copy of the License at http://www.flagstonesoftware.com/licenses/source.html
 *  and read it before using this file.
 *
 *  The Original Code and all software distributed under the License are distributed on an 
 *  'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, AND Flagstone 
 *  HEREBY DISCLAIMS ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF 
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT OF THIRD PARTY 
 *  RIGHTS. Please see the License for the specific language governing rights and limitations 
 *  under the License.
 */

#include "FSSetBackgroundColor.h"

#include "FSInputStream.h"
#include "FSOutputStream.h"

using namespace transform;

namespace transform
{
    FSSetBackgroundColor::FSSetBackgroundColor(FSInputStream* aStream) :
        FSMovieObject(SetBackgroundColor),
        color()
    {
        decodeFromStream(aStream);
    }

    const char* FSSetBackgroundColor::className() const
    {
        const static char _name[] = "FSSetBackgroundColor";

        return _name;
    }

    int FSSetBackgroundColor::lengthInStream(FSOutputStream* aStream)
    {
        FSMovieObject::lengthInStream(aStream);
        
        length += color.lengthInStream(aStream);
        
        return length;
    }
    
    void FSSetBackgroundColor::encodeToStream(FSOutputStream* aStream)
    {
        aStream->startEncoding(className());
        FSMovieObject::encodeToStream(aStream);
        
        color.encodeToStream(aStream);

        aStream->endEncoding(className());
    }
    
    void FSSetBackgroundColor::decodeFromStream(FSInputStream* aStream)
    {
        aStream->startDecoding(className());
        FSMovieObject::decodeFromStream(aStream);
        
        color.decodeFromStream(aStream);

        aStream->endDecoding(className());
    }
}