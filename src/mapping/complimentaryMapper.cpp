#include "ComplimentaryMapper.h"

void ComplimentaryMapper::setup(BaseInput *ip, BaseOutput *op1, BaseOutput *op2) {
    ip_ = ip;
    op_.one = op1;
    op_.two = op2;
    tgt_.one = tgt_.two = 0;
    prv_.one = prv_.two = 0;
}


void ComplimentaryMapper::update() {
    
    bool sweet = ip_->isSweetSpotOccupied();
    
    tgt_.one = sweet ? 100 : ip_->getMeanProximity(SECTOR_LEFT);
    tgt_.two = sweet ? 100 : ip_->getMeanProximity(SECTOR_RIGHT);

    if (tgt_.one != prv_.one) {
        op_.one->setLevel(tgt_.one > prv_.one ? ++prv_.one : --prv_.one);
    }
    
    if (tgt_.two != prv_.two) {
        op_.two->setLevel(tgt_.two > prv_.two ? ++prv_.two : --prv_.two);
    }

}