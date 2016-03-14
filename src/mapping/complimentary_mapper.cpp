#include "complimentary_mapper.h"

void ComplimentaryMapper::setup(BaseInput *input, BaseOutput *output1, BaseOutput *output2) {
    input_ = input;
    output_.one = output1;
    output_.two = output2;
    target_.one = target_.two = 0;
    previous_.one = previous_.two = 0;
}


void ComplimentaryMapper::update() {
    
    bool sweet = input_->sweetSpotOccupied();
    
    target_.one = sweet ? 100 : input_->meanProximity(SECTOR_LEFT);
    target_.two = sweet ? 100 : input_->meanProximity(SECTOR_RIGHT);

    if (target_.one != previous_.one) {
        output_.one->setLevel(target_.one > previous_.one ? ++previous_.one : --previous_.one);
    }
    
    if (target_.two != previous_.two) {
        output_.two->setLevel(target_.two > previous_.two ? ++previous_.two : --previous_.two);
    }

}