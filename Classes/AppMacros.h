#ifndef _APPMACROS_H_
#define _APPMACROS_H_

#include "GlobalPath.h"
#include "cocos2d.h"

//layer����������scene������ĸ��layer����LAYER
//layer��100+
#define HELLOWORLDLAYER 100

//HelloWorld�Ķ���
#define MAPLAYER 101
#define CONTROLPANELLAYER 102
#define COMBATLAYER 103

//MapLayer�Ķ���
#define MAP 590
#define HERO 510

//Map�Ķ���
#define MAN_START 36 

//ControlPanel�Ķ���
#define RWINDOW 521
#define BIGWINDOW 522
#define DIAWINDOW 523
#define DIRBUTTON 1
#define BUTTONA 10
#define TOUCHSCREEN 100

//Combat�Ķ���
#define BACKGROUND 100 

//Entity bind��sprite������IMGSP
#define IMGSP 500
#define DIABOXSP 501
#define LABELSP 502
#define CONTENTSP 503

//��ͼ�����������ͼ������_MLYR
#define EVENT_MLYR "event"
#define BUILDING2_MLYR "building2"
#define BUILDING_MLYR "building"
#define WALL_MLYR "wall"
#define FLOOR2_MLYR "floor2"
#define FLOOR_MLYR "floor"
#define WATER_MLYR "water"

//��Ϸ��¼������������������������_(M/S)RCD
#define FIRSTSAVE_RCD "FisrtSave"
#define POSITIONX_MRCD "PositionX"
#define POSITIONY_MRCD "PositionY"
#define FACEDIR_MRCD "FaceDirection"
#define MAPNO_MRCD "MapNo"
#define STORYCNT_MRCD "StoryCnt"
#define HAS_SHADOW_MRCD "HasShadow"
#define SH_STAND_P_MRCD "ShStandPos"
#define DAY_TIME_MRCD "StoryTime"
#define NIGHT_TIME_MRCD "NightStoryTime"

#define EVENTDONE_MRCD "EventDone"

#define SPEED_SRCD "Speed"
#define TELEPORT_SRCD "Teleport"
#define STEALTH_SRCD "Stealth"
#define SURF_SRCD "Surf"
#define FLASH_SRCD "Flash"
#define ALL_SUPERPOWER_SRCD "AllSuperPower"

#define EXP_CRCD "Exp"

//��Ϸ��¼�ĳ�ʼֵ����������������_INI
#define FIRSTSAVE_INI true
#define POSITIONX_INI 63
#define POSITIONY_INI 98
#define FACEDIR_INI 0
#define MAPNO_INI MAP11
#define STORYCNT_INI 0
#define HAS_SHADOW_INI false
#define SH_STAND_P_INI 2
#define DAY_TIME_INI 11
#define NIGHT_TIME_INI 31
#define EVENTDONE_INI ""

#define SPEED_INI 2.0
#define TELEPORT_INI false
#define STEALTH_INI false
#define SURF_INI false
#define FLASH_INI false
#define ALL_SUPERPOWER_INI false

#define EXP_INI 0

#define MAX_DONE_LIST 100
#define DEFUALT_DELIM ','

//����ֱ���
#define JX_RESOLUWID 1136
#define JX_RESOLUHEI 640
#define MAP_RESOLUWID 672
#define MAP_RESOLUHEI 448


//�¼������������¼�����_EVT
//�¼������ִ�����ʽ��վ������A����
//�¼��ڵ�ͼevent��
//վ������stand���ԣ�A������atrg����
//������������������������_ATT
#define STANDTRG_ATT "stand"
#define ATRG_ATT "atrg"
#define ID_ATT "id"

#define ROADSIGN_EVT "road sign"
#define TALKATIVEMAN_EVT "talkative man"

#define PORTAL_EVT "portal"
#define IDX_ATT "idx"
#define IDY_ATT "idy"

#define INFORMATION_GRP "information"
#define PLACENAMEID_OBJ "placenameID"
/*�½��¼��Ĳ��裺
1.ѡ��һ��������½�����stand/atrg=�¼�����id=������
2.��event������������ں��ʵ�λ�á�
(��Ϊplace name�¼���Ҫ�ڵ�ͼ��information������placenameID����������Ϊidֵ������ֵΪ����)
(��Ϊportal�¼�,����Ϊidx��idy��������Ŀ�ĵص�����)*/

#define MAP10 18
#define MAP11 19
#define MAP12 20

#define EGLVIEW 0.3
#define ZOOMSTROKELEN 200



/* define a event
 * 1. define Event subClass
 * 2. define Event Id here
 * 3. register with Event Loader
 * 4. for A Trig, register listener with eManaer listener()
 * 5. for A Trig, register notInstant with isInstant() 
 * 6. document the CSV arg protocal */

//For Event CSV
#define EVENT_ATT_NUM 9
#define A_TRIG 0
#define STAND_TRIG 1
#define STAND_TRIG_IMGNO -10
#define ATRIG_NO_MAN_IMGNO -1
#define MAP_SCALER 100
#define DAY_MAP_STATIC 10
#define NIGHT_MAP_STATIC 30

//Event Ids
#define NO_EVENT_FLAG -1
#define TALKMAN_EVT 0
#define GET_SUP_EVT 1
#define DIALOG_EVT 2
#define SHADOW_EVT 3
#define RELOAD_EVT 4
#define BLOODY_EVT 5
#define WATERY_EVT 6
#define DUEL_EVT 7
#define LNIGHT_EVT 8
#define LDAY_EVT 9

//Notification Center
#define HERO_STEP_UP_MSG "HeroStepUp"
typedef enum{kNone=1,kWall=17,kEvent=41}CollisionType;
typedef enum{Down=0,Left=1,Right=2,Up=3}FaceDirection;

//zorders
#define HERO_ON_MAP_ZOR 5
#define HERO_MOVE_BACK_ZOR 3
#define NPC_ON_MAP_BACK_ZOR 4
#define NPC_ON_MAP_FRON_ZOR 6
#define HERO_ON_PANEL_ZOR 3
#define PANEL_ON_MAPLYR_ZOR 15
#define WIN_ON_PANEL_ZOR 11
#define NIGHT_ON_PANEL_ZOR 20
#define BLACK_ON_PANEL_ZOR 21

//switches
#define DEBUG_MODE true
#define HERO_COVER_MODE FALSE
#define TRUE 1
#define FALSE 0

//night fall
#define DAYTIME_OPACITY 0
#define NIGHTTIME_OPACITY 150
#endif /* __APPMACROS_H__ */
