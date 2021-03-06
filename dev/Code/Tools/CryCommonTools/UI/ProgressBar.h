/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/
// Original file Copyright Crytek GMBH or its affiliates, used under license.

#ifndef CRYINCLUDE_CRYCOMMONTOOLS_UI_PROGRESSBAR_H
#define CRYINCLUDE_CRYCOMMONTOOLS_UI_PROGRESSBAR_H
#pragma once


#include "IUIComponent.h"

class ProgressBar
    : public IUIComponent
{
public:
    ProgressBar();

    void SetProgress(float progress);

    // IUIComponent
    virtual void CreateUI(void* window, int left, int top, int width, int height);
    virtual void Resize(void* window, int left, int top, int width, int height);
    virtual void DestroyUI(void* window);
    virtual void GetExtremeDimensions(void* window, int& minWidth, int& maxWidth, int& minHeight, int& maxHeight);

private:
    void* m_progressBar;
};

#endif // CRYINCLUDE_CRYCOMMONTOOLS_UI_PROGRESSBAR_H
