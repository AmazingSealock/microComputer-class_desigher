#define  uint  unsigned int
#define  uchar unsigned char

uchar   var[142]      _at_ 0x130;	   //设置参数, 78 bytes parameter + 2 bytes blank, 62 bytes 标定系数

uchar   iden_code     _at_ 0x130;
uchar   null_n        _at_ 0x131;
uchar   comm_addr     _at_ 0x132;
uchar   baud          _at_ 0x133;
 
uchar   in_mod[2]     _at_ 0x134;	   //输入信号方式
uchar   sqrt_m[2]     _at_ 0x136;	   //0--不开方， 1--开方
float   ms_hih[2]     _at_ 0x138;
float   ms_low[2]     _at_ 0x140;

uchar   out_mod[2]    _at_ 0x148;	   //输出信号方式
float   cov_hih[2]    _at_ 0x14a;	   //变送上限
float   cov_low[2]    _at_ 0x152;	   //变送下限

float   alm_A1_val    _at_ 0x15a;	   //因为所有有报警的模块均为单入单出产品，所以只需一组报警参数(对应单入）
float   alm_A2_val    _at_ 0x15e;      //A1可上限报警（H）,也可下限报警（L）； A2可上限报警（H）,也可下限报警（L）
uchar   alm_sta[2]    _at_ 0x162;	   //若H L，则为上限下限报警；若为H H，则为上限和上上限报警； 若为L L，则为下限和下下限报警；
                                       //0--NO, 1--H,  2--L

float   in_low_alm[2] _at_ 0x164;	   //单位mA, 若为报警状态，当测量值对应的输出值(mA)小于in_low_alm时，输出一固定值in_alm_out(mA);
float   in_hih_alm[2] _at_ 0x16c;	   //单位mA, 若为报警状态，当测量值对应的输出值(mA)大于in_hih_alm时，输出一固定值in_alm_out(mA);
float   in_alm_out[2] _at_ 0x174;	   //单位mA，报警时输出的固定电流值(0~22mA)；
uchar   alm_ou_sta[2] _at_ 0x17c;      //0--follow, 1--alarm, 2--keep                                      
									   //0x17e, 0x17f 空2bytes

uchar   var1[84]      _at_ 0x180;	   //标定系数86 bytes + 2 bytes blank

float   cal_100[2]    _at_ 0x180;
float   cal_20[2]	  _at_ 0x188;
float   cal_5[2]      _at_ 0x190;
float   cal_rtd[2]    _at_ 0x198;
float   cal_out[2]    _at_ 0x1a0;
float   cal_cold      _at_ 0x1a8;
float   amp_zero[4]   _at_ 0x1ac;
uchar   out_zero[2]   _at_ 0x1bc;

float   com_cal[2]    _at_ 0x1be;	   //临时通讯
float   com_zero[4]   _at_ 0x1c6;	   //临时通讯

uint    verify_add	  _at_ 0x1d6;	   //var[166]-0x1d6, var[167]-0x1d7

uchar   comm[20]      _at_ 0x1da;	   //实时测量值
float   AD_OUT[2]     _at_ 0x1da;
float   DA_OUT[2]     _at_ 0x1e2;
float   cold          _at_ 0x1ea;
