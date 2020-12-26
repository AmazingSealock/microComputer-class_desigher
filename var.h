#define  uint  unsigned int
#define  uchar unsigned char

uchar   var[142]      _at_ 0x130;	   //���ò���, 78 bytes parameter + 2 bytes blank, 62 bytes �궨ϵ��

uchar   iden_code     _at_ 0x130;
uchar   null_n        _at_ 0x131;
uchar   comm_addr     _at_ 0x132;
uchar   baud          _at_ 0x133;
 
uchar   in_mod[2]     _at_ 0x134;	   //�����źŷ�ʽ
uchar   sqrt_m[2]     _at_ 0x136;	   //0--�������� 1--����
float   ms_hih[2]     _at_ 0x138;
float   ms_low[2]     _at_ 0x140;

uchar   out_mod[2]    _at_ 0x148;	   //����źŷ�ʽ
float   cov_hih[2]    _at_ 0x14a;	   //��������
float   cov_low[2]    _at_ 0x152;	   //��������

float   alm_A1_val    _at_ 0x15a;	   //��Ϊ�����б�����ģ���Ϊ���뵥����Ʒ������ֻ��һ�鱨������(��Ӧ���룩
float   alm_A2_val    _at_ 0x15e;      //A1�����ޱ�����H��,Ҳ�����ޱ�����L���� A2�����ޱ�����H��,Ҳ�����ޱ�����L��
uchar   alm_sta[2]    _at_ 0x162;	   //��H L����Ϊ�������ޱ�������ΪH H����Ϊ���޺������ޱ����� ��ΪL L����Ϊ���޺������ޱ�����
                                       //0--NO, 1--H,  2--L

float   in_low_alm[2] _at_ 0x164;	   //��λmA, ��Ϊ����״̬��������ֵ��Ӧ�����ֵ(mA)С��in_low_almʱ�����һ�̶�ֵin_alm_out(mA);
float   in_hih_alm[2] _at_ 0x16c;	   //��λmA, ��Ϊ����״̬��������ֵ��Ӧ�����ֵ(mA)����in_hih_almʱ�����һ�̶�ֵin_alm_out(mA);
float   in_alm_out[2] _at_ 0x174;	   //��λmA������ʱ����Ĺ̶�����ֵ(0~22mA)��
uchar   alm_ou_sta[2] _at_ 0x17c;      //0--follow, 1--alarm, 2--keep                                      
									   //0x17e, 0x17f ��2bytes

uchar   var1[84]      _at_ 0x180;	   //�궨ϵ��86 bytes + 2 bytes blank

float   cal_100[2]    _at_ 0x180;
float   cal_20[2]	  _at_ 0x188;
float   cal_5[2]      _at_ 0x190;
float   cal_rtd[2]    _at_ 0x198;
float   cal_out[2]    _at_ 0x1a0;
float   cal_cold      _at_ 0x1a8;
float   amp_zero[4]   _at_ 0x1ac;
uchar   out_zero[2]   _at_ 0x1bc;

float   com_cal[2]    _at_ 0x1be;	   //��ʱͨѶ
float   com_zero[4]   _at_ 0x1c6;	   //��ʱͨѶ

uint    verify_add	  _at_ 0x1d6;	   //var[166]-0x1d6, var[167]-0x1d7

uchar   comm[20]      _at_ 0x1da;	   //ʵʱ����ֵ
float   AD_OUT[2]     _at_ 0x1da;
float   DA_OUT[2]     _at_ 0x1e2;
float   cold          _at_ 0x1ea;
