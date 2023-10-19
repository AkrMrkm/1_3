/**
* @file manualTest.h
* @brief �蓮�e�X�gcpp
* @author ����P
* @date 2023/10/19/11:30
* @details �ۑ�1_3�u�o�������X�g�̃e���v���[�g���v\n
*/

#include "pch.h"
#include "manualTest.h"
#include "../DoubleList3/doublyLinkedList.h"
#include "../DoubleList3/recordData.h"

/**********************************************************************************//**
	@brief		�f�[�^���̎擾�@�\�ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
	@details	ID:���X�g-8(�蓮)\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
				�L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
				TT_TEST_GET_DATA_NUM_IS_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/
TEST(ListManualTest, Test_GetDataNum_WhenConst)
{
#if defined TT_TEST_GET_DATA_NUM_WHEN_CONST
	const DoublyLinkedList<RecordData> list;
	EXPECT_EQ(0, list.GetDataNum());
#endif //TT_TEST_GET_DATA_NUM_WHEN_CONST
	SUCCEED();
}


/**********************************************************************************//**
	@brief		���X�g�����̃f�[�^�ǉ��ɂ��āA��const���ۏႳ��Ă��邩�̃e�X�g
	@details	ID:���X�g-15(�蓮)\n
				���X�g�����̃f�[�^�ǉ��e�X�g�ł��B\n
				��const���ۏႳ��Ă��邩���m�F���Ă��܂��B\n
				�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
				TT_TEST_PUSH_IS_NOT_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/
TEST(ListManualTest, Test_Insert_WhenConst)
{
#if defined TT_TEST_INSERT_WHEN_CONST
	const DoublyLinkedList<RecordData> list;
	DoublyLinkedList<RecordData>::ConstIterator it = list.GetCBegin();
	RecordData data{ 1, "a" };
	list.Insert(it, data);//�����ŃG���[
#endif //TT_TEST_INSERT_WHEN_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		��const�̃��\�b�h�ł��邩
	@details	ID:���X�g-22\

				�R���p�C���G���[�Ő���\n
*//***********************************************************************************/
TEST(ListManualTest, Test_Remove_WhenConst)
{
#if defined TT_TEST_REMOVE_WHEN_CONST
	const DoublyLinkedList<RecordData> list;
	DoublyLinkedList<RecordData>::ConstIterator it = list.GetCBegin();
	list.Remove(it); // �����ŃG���[
#endif //TT_TEST_REMOVE_WHEN_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
	@details	ID:���X�g-28\n
				�R���p�C���G���[�Ő���\n
*//***********************************************************************************/
TEST(ListManualTest, TestGetBegin_Const)
{
#if defined TT_TEST_BEGIN_WHEN_NO_CONST
	const DoublyLinkedList<RecordData> list;
	DoublyLinkedList<RecordData>::Iterator it = list.GetBegin();// �����ŃG���[
#endif //TT_TEST_BEGIN_WHEN_NO_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		const�̃��\�b�h�ł��邩
	@details	ID:���X�g-34\n
				�R���p�C���G���[���ʂ�ΐ���\n
*//***********************************************************************************/
TEST(ListManualTest, Test_GetBegin_Const)
{
#if defined TT_TEST_BEGIN_WHEN_CONST
	const DoublyLinkedList<RecordData> list;
	DoublyLinkedList<RecordData>::ConstIterator it = list.GetCBegin();
#endif //TT_TEST_BEGIN_WHEN_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
	@details	ID:���X�g-40\n
				�R���p�C���G���[�Ő���\n
*//***********************************************************************************/
TEST(ListManualTest, Test_GetEnd_Const)
{
#if defined TT_TEST_END_WHEN_NO_CONST
	const DoublyLinkedList<RecordData> list;
	DoublyLinkedList<RecordData>::Iterator it = list.GetEnd();// �����ŃG���[
#endif //TT_TEST_END_WHEN_NO_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		const�̃��\�b�h�ł��邩
	@details	ID:���X�g-46\n
				�R���p�C�����ʂ�ΐ���\n
*//***********************************************************************************/
TEST(ListManualTest, TestGetEnd_Const)
{
#if defined TT_TEST_END_WHEN_CONST
	const DoublyLinkedList<RecordData> list;
	DoublyLinkedList<RecordData>::ConstIterator it = list.GetCEnd();
#endif //TT_TEST_END_WHEN_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		ConstIterator����擾�����v�f�ɑ΂��āA�l�̑�����s���邩���`�F�b�N
	@details	ID:���X�g-2\n
				�R���p�C���G���[�ɂȂ邱�Ƃ��`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B\n
*//***********************************************************************************/
TEST(ListManualTest, Test_Assign_ConstIt)
{
#if defined TT_TEST_ITE_ASSIGN_CONST
	DoublyLinkedList<RecordData> list;
	DoublyLinkedList<RecordData>::ConstIterator it = list.GetBegin();
	RecordData data{ 1, "a" };
	*it = data;
#endif //TT_TEST_ITE_ASSIGN_CONST
	SUCCEED();
}



//===================================�C�e���[�^�̃R�s�[���s��===================================

/**********************************************************************************//**
	@brief		ConstIterator����AIterator�̃R�s�[���쐬����Ȃ������`�F�b�N
	@details	ID:���X�g-17\n
				�R���p�C���G���[�ɂȂ邱�Ƃ��m�F����B�����e�X�g�����Ȃ��Ă悢�B\n
*//***********************************************************************************/
TEST(ListManualTest, Test_Copy_Const)
{
#if defined TT_TEST_COPY_WHEN_CONST
	DoublyLinkedList<RecordData> list;
	DoublyLinkedList<RecordData>::ConstIterator cit = list.GetBegin();
	DoublyLinkedList<RecordData>::Iterator cit = cit;
#endif //TT_TEST_COPY_WHEN_CONST
	SUCCEED();
}




//===================================�C�e���[�^�̑�����s��===================================

/**********************************************************************************//**
	@brief		Iterator��ConstIterator�����ł��Ȃ������`�F�b�N
	@details	ID:���X�g-19\n
				�R���p�C���G���[�ɂȂ邱�Ƃ��m�F����B�����e�X�g�����Ȃ��Ă悢�B\n
*//***********************************************************************************/
TEST(ListManualTest, Test_Assign_Const)
{
#if defined TT_TEST_ASSIGN_WHEN_CONST
	DoublyLinkedList<RecordData> list;
	DoublyLinkedList<RecordData>::ConstIterator cit = list.GetBegin();
	DoublyLinkedList<RecordData>::Iterator it = list.GetBegin();
	it = cit; // �����ŃG���[
#endif //TT_TEST_ASSIGN_WHEN_CONST
	SUCCEED();
}