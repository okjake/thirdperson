#include "LinearMapper.h"

void LinearMapper::setup(BaseInput *input, BaseOutput *output, SWEETSPOT_SECTOR sector) {
    input_  = input;
    output_ = output;
    target_ = previous_ = 0;
    sector_ = sector;
}

void LinearMapper::update() {
    target_ = input_->sweetSpotOccupied() ? 100 : input_->meanProximity(sector_);
    if (target_ == previous_) {
        return;
    }
    output_->setLevel(target_ > previous_ ? ++previous_ : --previous_);
    
}