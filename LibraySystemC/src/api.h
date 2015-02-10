/******************************************************************************


                  ��Ȩ���� (C), 2009-2009, ��Ϊ�������޹�˾


 ******************************************************************************
  �� �� ��   : api.h
  �� �� ��   : ����
  ��    ��   :
  ��������   : 2009��9��9��
  ����޸�   :
  ��������   : api.cpp ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2009��9��9��
    ��    ��   :
    �޸�����   : �����ļ�
******************************************************************************/

#ifndef __API_H__
#define __API_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** ���ļ��е�ö�١��ṹ��API�ӿڵȹ�����ʹ�ê����������޸� **/

//���ز�����Ϣ
enum OP_RST_INFO
{
    S001,        //��ʼ���ɹ�
    S002,        //¼��Υ���¼�ɹ�
    E001,        //ϵͳδ��ʼ��
    E002,        //����ʱ�䳬��ϵͳ������Χ
    E003,        //����Υ�����ͳ���ϵͳ������Χ
    E004,        //�����ѵ���������ʧ��
    E005,        //������ɽ���ϵͳ������Χ
    E006,        //���ɶ�����Ч
    E007,        //��Υ���¼������Ҫ���ɷ���
    E008,        //ʱ�����С���ϴβ���ʱ��
    E009,        //Υ���¼����
    E010,        //��Υ���¼
    E999         //ϵͳ�ڲ�����
};

//����Υ����Ϣ
typedef struct CAR_SYS_INFO
{
    int     Time;                                      //Υ��ʱ��
    int     Reason;                                    //Υ��ԭ��
    int     Fee;                                      //������
    int     Credit;                                   //Ӧ�۳�����
    int     Index;                                    //��ʷΥ���¼���
} CarSysInfo;

//��ʷΥ����Ϣ
typedef struct QUERY_RESULT
{
    int             Index;                             //��ʷΥ�����
    int             Time;                              //Υ��ʱ��
    int             Reason;                            //Υ��ԭ��
    int             Fee;                               //������
    enum enPayStat  PayFlag;                           //�����Ƿ��Ѿ�����(0��δ���ɷ��1���ѽ��ɷ���)
    int             Score;                             //ʣ�����
} QueryResult;

typedef struct tagQUERY_RESULTNode
{
    QueryResult                     data;
    struct  tagQUERY_RESULTNode   *pNext;
} QUERY_RESULTNode;

//���ɷ��������Ϣ
typedef struct PAY_RESULT
{
    int     ReturnMoney;                               //����
    int     Score;                                     //ʣ�����
    int     PeccancyNo;                                //ʣ��Υ���¼��
    int     Fee;                                       //ʣ�෣����
} PayResult;

/*****************************************************************************
 �� �� ��  : api_print_result
 ��������  : ��ӡ��������Ϣ��socket���ߴ���
 �������  : enum OP_RST_INFO enResultCode
 �������  : ��
 �� �� ֵ  : extern void
 ���ú���  :
 ��������  :
 �޸���ʷ  :
  1.��    ��   : 2010��1��21��
    ��    ��   :
    �޸�����   : �����ɺ���
*****************************************************************************/
void api_print_result(enum OP_RST_INFO enResultCode);


/*****************************************************************************
 �� �� ��  : api_print_query_info
 ��������  : ��ӡ��ѯ��Ϣ��socket���ߴ���
 �������  : QueryResult *pResult
 �������  : ��
 �� �� ֵ  : extern void
 ���ú���  :
 ��������  :
 �޸���ʷ  :

  1.��    ��   : 2010��1��21��
    ��    ��   :
    �޸�����   : �����ɺ���

*****************************************************************************/
void api_print_query_info(QueryResult *pResult);


/*****************************************************************************
 �� �� ��  : api_print_pay_info
 ��������  : ��ӡ������Ϣ��socket���ߴ���
 �������  : PayResult  *pResult
 �������  : ��
 �� �� ֵ  : extern void
 ���ú���  :
 ��������  :
 �޸���ʷ  :
  1.��    ��   : 2010��1��21��
    ��    ��   :
    �޸�����   : �����ɺ���
*****************************************************************************/
void api_print_pay_info(PayResult  *pResult);


/*****************************************************************************
 �� �� ��  : api_server_start
 ��������  : ����socket����˪��������ķ�ʽ�����û�����
 �������  : ��
 �������  : ��
 �� �� ֵ  : extern void
 ���ú���  :
 ��������  :
 �޸���ʷ  :
  1.��    ��   : 2010��1��21��
    ��    ��   :
    �޸�����   : �����ɺ���
*****************************************************************************/
void api_server_start(int argc, char* argv[]);


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* __API_H__ */