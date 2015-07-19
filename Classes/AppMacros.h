#ifndef _APPMACROS_H_
#define _APPMACROS_H_

#include "GlobalPath.h"
#include "cocos2d.h"
//last: 2014-9-29 13:23:33
//update: 2014-11-17 18:08:39


//layer����������scene������ĸ��layer����LAYER
//layer��100+
#define HELLOWORLDLAYER 100

//HelloWorld�Ķ���
#define MAPLAYER 101
#define CONTROLPANELLAYER 102

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
#define EVENTDONE_MRCD "EventDone"

#define SPEED_SRCD "Speed"
#define TELEPORT_SRCD "Teleport"
#define STEALTH_SRCD "Stealth"
#define SURF_SRCD "Surf"
#define FLASH_SRCD "Flash"
#define ALL_SUPERPOWER_SRCD "AllSuperPower"

//��Ϸ��¼�ĳ�ʼֵ����������������_INI
#define FIRSTSAVE_INI true
#define POSITIONX_INI 63
#define POSITIONY_INI 98
#define FACEDIR_INI 0
#define MAPNO_INI MAP11
#define STORYCNT_INI 0
#define EVENTDONE_INI ""

#define SPEED_INI 2.0
#define TELEPORT_INI false
#define STEALTH_INI false
#define SURF_INI false
#define FLASH_INI false
#define ALL_SUPERPOWER_INI false

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
#define NSTR_ATT "nstr"

#define PORTAL_EVT "portal"
#define IDX_ATT "idx"
#define IDY_ATT "idy"

#define CHANGESCENE_EVT "change scene"
#define MAP11 19
#define MAP12 20
#define EVENT_MAP11 0
#define EVENT_MAP12 1



#define ANIMATE_EVT "animate"
#define PLACENAME_EVT "place name"

/*�½��¼��Ĳ��裺
1.ѡ��һ��������½�����stand/atrg=�¼�����id=������
2.��event������������ں��ʵ�λ�á�
//3.��Ϊatrg�¼�����wall���Ӧλ�û������
(��Ϊplace name�¼���Ҫ�ڵ�ͼ��information������placenameID����������Ϊidֵ������ֵΪ����)
(��Ϊportal�¼�,����Ϊidx��idy��������Ŀ�ĵص�����)
(��Ϊtalkative man�¼���id�Ƕ�Ӧ��ĸ��'a'������nstrΪ���м��仰������0~9Ϊ���ֵ)
����Ϣ���ڿ�������������ÿ���¼���Ҫһ����һ���Ŀ����
���Ǽ�ʹ�����ֲ�����һ����Ҳ���ǵ�ÿ��һ�������*/


#define INFORMATION_GRP "information"
#define	TURNINGMAN_OBJ "turningMan"
#define STANDINGMAN_OBJ "standingMan"
#define PLACENAMEID_OBJ "placenameID"

#define NNPC_ATT "nnpc"
#define NPCAX_ATT "npcax"

#define TURNINGMAN_ATTNUM 3
#define STANDINGMAN_ATTNUM 4
#define MARK 100

#define EGLVIEW 0.3
#define ZOOMSTROKELEN 200



/* define a event
 * 1. define Event subClass
 * 2. define Event Id here
 * 3. register with Event Loader
 * 4. for A Trig, register listener with eManaer listener()
 * 5. for Stand Trig, register instant with isInstant() */

//For Event CSV
#define EVENT_ATT_NUM 9
#define A_TRIG 0
#define STAND_TRIG 1
#define STAND_TRIG_IMGNO -10
#define ATRIG_NO_MAN_IMGNO -1

//Event Ids
#define NO_EVENT_FLAG -1
#define TALKMAN_EVT 0
#define GET_SUP_EVT 1

typedef enum{kNone=1,kWall=17,kEvent=41}CollisionType;
typedef enum{Down=0,Left=1,Right=2,Up=3}FaceDirection;

#endif /* __APPMACROS_H__ */
