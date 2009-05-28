/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_RS_STRUCTURED_COMPONENT_H
#define ANDROID_RS_STRUCTURED_COMPONENT_H

#include <stdint.h>
#include <sys/types.h>
#include <stdlib.h>

#include "RenderScript.h"
#include "rsObjectBase.h"

// ---------------------------------------------------------------------------
namespace android {
namespace renderscript {

class Component : public ObjectBase
{
public:
    enum DataType {
        FLOAT,
        UNSIGNED,
        SIGNED
    };

    enum DataKind {
        NONE,
        RED, GREEN, BLUE, ALPHA, LUMINANCE, INTENSITY,
        X, Y, Z, W,
        S, T, Q, R,
        NX, NY, NZ,
        INDEX,
        USER
    };


    Component(DataKind dk, DataType dt, bool isNormalized, uint32_t bits);
    virtual ~Component();

    DataType getType() const {return mType;}
    bool getIsNormalized() const {return mIsNormalized;}
    DataKind getKind() const {return mKind;}
    uint32_t getBits() const {return mBits;}

protected:

    DataType mType;
    bool mIsNormalized;
    DataKind mKind;
    uint32_t mBits;

private:
    Component();
};


}
}

#endif //ANDROID_RS_STRUCTURED_COMPONENT_H
