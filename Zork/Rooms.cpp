#include <stdio.h>
#include <stdlib.h>
#include "Rooms.h"
#include "Exits.h"
#include "Player.h"
#include "World.h"

Reception Room ->setExits(NULL, NULL, WC, Living room);
WC ->setExits(NULL, NULL, Control Room, Reception room);
Control room->setExits (Secret room, WC, Dinning room Exit);
Dinning room->setExits (NULL, NULL, NULL, NULL);
Secret room->setExits (NULL, Cave, Control room, Disco room);
Cave->setExits (Secret room, Final boss, NULL, NULL);
Final boss->setExits (Cave, NULL, NULL, NULL);
Disco room->setExits (NULL, Bunker, Secret room, Living room);
Bunker ->setExits (Disco room, NULL, NULL, NULL);
Living room ->setExits (Disco room, NULL, Reception room, Terrace);
Terrace ->setExits (NULL, Living Room, NULL, NULL);


