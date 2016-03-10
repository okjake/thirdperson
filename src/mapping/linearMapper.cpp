#include "LinearMapper.h"

void LinearMapper::setup(BaseInput *ip, BaseOutput *op, SWEETSPOT_SECTOR sector) {
    ip_ = ip;
    op_ = op;
    tgt_ = prv_ = 0;
    sector_ = sector;
}

void LinearMapper::update() {
    tgt_ = ip_->isSweetSpotOccupied() ? 100 : ip_->getMeanProximity(sector_);
    if (tgt_ == prv_) { return; }
    op_->setLevel(tgt_ > prv_ ? ++prv_ : --prv_);
    
}