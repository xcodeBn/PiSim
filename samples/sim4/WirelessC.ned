//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


package samples.sim4;

import inet.environment.common.PhysicalEnvironment;


network WirelessC extends WirelessB
{
    submodules:
        physicalEnvironment: PhysicalEnvironment {
            @display("p=580,425");
        }
}