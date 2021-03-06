//
// Created by wojciech on 29.05.17.
//

#include "AnimationSequence.h"

void AnimationSequence::addToSequence(std::shared_ptr<Animation>&& animation) {
    mDuration += animation->getDuration();
    mAnimations.emplace_back(std::move(animation));
}


void AnimationSequence::animationStart() {
    Animation::animationStart();
    if (!mAnimations.empty())
        mAnimations[0]->animationStart();
}

bool AnimationSequence::animationStep(GLfloat delta) {
    if (mRunning) {
        auto&& step = mAnimations[mCurrentAnimation];
        if (step->animationStep(delta)) {
            if (mCurrentAnimation < mAnimations.size() - 1) {
                mCurrentAnimation++;
                mAnimations[mCurrentAnimation]->animationStart();
                return false;
            } else if (mLooped) {
                animationReset();
                animationStart();
                return false;
            } else {
                mRunning = false;
                return true;
            }
        }
        return false;
    }
    return true;
}

void AnimationSequence::animationReset() {
    Animation::animationReset();
    mCurrentAnimation = 0;
    for(auto it  = mAnimations.rbegin(); it != mAnimations.rend(); ++it)
        (*it)->animationReset();
}

