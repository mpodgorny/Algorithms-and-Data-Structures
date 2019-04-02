//
// Created by dtend on 02.04.2019.
//

#ifndef ASD_L1_RNGGOOD_H
#define ASD_L1_RNGGOOD_H
//
// Created by dtend on 02.04.2019.
//

#include <stdint.h>
#define CMWC_CYCLE 4096 // as Marsaglia recommends
#define CMWC_C_MAX 80943066
struct cmwc_state {
    uint32_t Q[CMWC_CYCLE];
    uint32_t c;	// must be limited with CMWC_C_MAX
    unsigned i;
};
uint32_t rand32(void);
void initCMWC(struct cmwc_state *state, unsigned int seed);
uint32_t randCMWC(struct cmwc_state *state) ; //EDITED parameter *state was missing

#endif //ASD_L1_RNGGOOD_H
