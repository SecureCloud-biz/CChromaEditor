#include "stdafx.h"
#include "EditorAnimation1D.h"
#include "ChromaSDKPlugin.h"

using namespace ChromaSDK;
using namespace std;

EditorAnimation1D::EditorAnimation1D()
{
	Reset();
}

AnimationBase* EditorAnimation1D::GetAnimation()
{
	return &_mAnimation;
}

void EditorAnimation1D::SetAnimation(Animation1D& animation)
{
	_mAnimation = animation;
}

EChromaSDKDevice1DEnum EditorAnimation1D::GetDevice()
{
	return _mAnimation.GetDevice();
}

bool EditorAnimation1D::SetDevice(EChromaSDKDevice1DEnum device)
{
	if (_mAnimation.SetDevice(device))
	{
		Reset();
		return true;
	}
	else
	{
		return false;
	}
}

vector<FChromaSDKColorFrame1D>& EditorAnimation1D::GetFrames()
{
	return _mAnimation.GetFrames();
}

void EditorAnimation1D::Reset()
{
	EChromaSDKDevice1DEnum device = GetDevice();
	_mFrameCopy.Colors = ChromaSDKPlugin::GetInstance()->CreateColors1D(device);
}

void EditorAnimation1D::SetCopy(FChromaSDKColorFrame1D& copy)
{
	_mFrameCopy = copy;
}

FChromaSDKColorFrame1D& EditorAnimation1D::GetCopy()
{
	return _mFrameCopy;
}

void EditorAnimation1D::OverrideTime(float time)
{
	vector<FChromaSDKColorFrame1D>& frames = GetFrames();
	for (unsigned int i = 0; i < frames.size(); ++i)
	{
		FChromaSDKColorFrame1D& frame = frames[i];
		frame.Duration = time;
	}
}

float EditorAnimation1D::GetDuration(unsigned int index)
{
	vector<FChromaSDKColorFrame1D>& frames = GetFrames();
	if (index < frames.size())
	{
		FChromaSDKColorFrame1D& frame = frames[index];
		return frame.Duration;
	}
	return 0.0f;
}
