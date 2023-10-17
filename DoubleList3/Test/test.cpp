/**
* @file test.cpp
* @brief �����e�X�g
* @author ����P
* @date 2023/10/17/15:00
* @details �ۑ�1_3�u�o�������X�g�̃e���v���[�g���v
*/

#include "pch.h"
#include "test.h"


namespace ex01_DataStructure
{
	namespace chapter1
	{
		//=================================== �f�[�^���̎擾 ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-0\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						���X�g����ł���ꍇ�̖߂�l���m�F���Ă��܂��B\n
						�f�[�^����0�ł���ΐ����ł��B\n
						�f�[�^������̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(EmptyListTest, ID_0_0_Test_GetDataNum_WhenEmpty)
		{
			EXPECT_EQ(0, m_List->GetDataNum()) << "���X�g����ł���ꍇ�̃f�[�^�̎擾�Ɏ��s";
		}

		/**********************************************************************************//**
			@brief		���X�g�����ւ̑}�����s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-1\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						���X�g�����ւ̑}�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^����1�����Ă���ΐ����ł��B\n
						�f�[�^������̃��X�g���g�p\n
		 *//***********************************************************************************/
		TEST_F(EmptyListTest, ID_0_1_Test_GetDataNum_InsertEnd)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();

			ASSERT_TRUE(m_List->Insert(it, g_data[0])); // �f�[�^���ЂƂ}��

			EXPECT_EQ(1, m_List->GetDataNum()) << "���X�g�����ւ̑}�����s�����ۂ̃f�[�^�̎擾�Ɏ��s";
		}

		/**********************************************************************************//**
			@brief		���X�g�����ւ̑}�������s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-2\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						���X�g�����ւ̑}�������s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^���������Ă��Ȃ���ΐ����ł��B\n
		//*//***********************************************************************************/
		TEST(GetDataNumTest, ID_0_2_Test_GetDataNum_InsertEnd_Failed)
		{
			// "�����ւ�"�}�����s�̓������m�ێ��s���̂��߂����ł̓X�L�b�v
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̑}�����s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-3\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̑}�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^����1�ł���ΐ����ł��B\n
						�f�[�^������̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(EmptyListTest, ID_0_3_Test_GetDataNum_Insert)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();

			ASSERT_TRUE(m_List->Insert(it, g_data[0])); // �f�[�^���ЂƂ}��

			EXPECT_EQ(1, m_List->GetDataNum()) << "�f�[�^�̑}�����s�����ۂ̃f�[�^�̎擾�Ɏ��s";
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̑}���Ɏ��s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-4\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̑}�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^����0�ł���ΐ����ł��B\n
		*//***********************************************************************************/

		TEST(GetDataNumTest, ID_0_4_Test_GetDataNum_Insert_Failed)
		{
			// �}�����s�̓������m�ێ��s���̂��߂����ł̓X�L�b�v
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̍폜���s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-5\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̍폜���s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�ŏ��Ƀf�[�^���ЂƂ}�����āA�폜���s���Ă��܂��B\n
						�f�[�^����0�ł���ΐ����ł��B\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(OneDataListTest, ID_0_5_Test_GetDataNum_Remove)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();

			m_List->Remove(it);

			EXPECT_EQ(0, m_List->GetDataNum()) << m_List->GetDataNum() << "�f�[�^�̍폜���s�����ۂ̃f�[�^�̎擾�Ɏ��s";
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̍폜�Ɏ��s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-6\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̍폜���s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�ŏ��Ƀf�[�^���ЂƂ}�����āA�폜���s���Ă��܂��B\n
						�f�[�^����1�ł���ΐ����ł��B\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(OneDataListTest, ID_0_6_Test_GetDataNum_Remove_Failed)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetEnd();

			m_List->Remove(it);

			EXPECT_EQ(1, m_List->GetDataNum()) << m_List->GetDataNum() << "�f�[�^�̍폜�Ɏ��s�����ۂ̃f�[�^�̎擾�Ɏ��s";
		}

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�Ƀf�[�^�̍폜�������ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-7\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̍폜���s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^�����}�C�i�X�łȂ���ΐ����ł��B\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(EmptyListTest, ID_0_7_Test_GetDataNum_Remove_Empty)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();

			ASSERT_FALSE(m_List->Remove(it));

			EXPECT_EQ(0, m_List->GetDataNum());
		}

		// 8�̓}�j���A���e�X�g

		//=================================== �f�[�^�̑}�� ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�}�������ۂ̋���
			@details	ID:���X�g-9\n
						���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
						�擪�C�e���[�^�A�����C�e���[�^�������œn�����ꍇ�ɂ��āA�ʂɋ������`�F�b�N���邱��\n
						2�̋�̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(TwoEmptyListTest, ID_0_9_Test_Insert_Empty)
		{
			// �擪�ɑ}��
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
				EXPECT_TRUE(m_List->Insert(it, g_data[0]));
				EXPECT_EQ(1, m_List->GetDataNum());
			}

			// �����ɑ}��
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List_2->GetEnd();
				EXPECT_TRUE(m_List_2->Insert(it, g_data[0]));
				EXPECT_EQ(1, m_List_2->GetDataNum());
			}
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�}�������ۂ̋����e�X�g
			@details	ID:���X�g-10\n
						�擪�ɗv�f���}������A���X�擪�������v�f���Q�ԖڂɂȂ�ΐ����ł��B\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_0_10_Test_Insert_Begin)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();

			// �擪��5��}��
			ASSERT_TRUE(m_List->Insert(it, g_data[5]));

			//�擪�������v�f����ԖڂɂȂ��Ă����琬��(���Ԃ�501234�ɂȂ��Ă����琬��)
			it = m_List->GetBegin();
			RecordData itData = *it;
			EXPECT_EQ(5, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(0, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(1, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(3, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(4, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�}�������ۂ̋����e�X�g
			@details	ID:���X�g-11\n
						�C�e���[�^�̎w���ʒu�ɗv�f���}�������\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_0_11_Test_Insert_End)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetEnd();

			// ������5��}��
			ASSERT_TRUE(m_List->Insert(it, g_data[5]));

			// (���Ԃ�012345�ɂȂ��Ă����琬��)
			it = m_List->GetBegin();
			RecordData itData = *it;
			EXPECT_EQ(0, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(1, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(3, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(4, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(5, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���đ}�������ۂ̋����e�X�g
			@details	ID:���X�g-12\n
						TRUE�Ő���\n
						�i�[�ς݂̗v�f�ɉe�����Ȃ����A���҂����ʒu�ɗv�f���i�[����Ă��邩\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_0_12_Test_Insert_Other)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
			++it;
			++it;
			++it;

			// �擪����4�Ԗڂ�5��}��
			ASSERT_TRUE(m_List->Insert(it, g_data[5]));

			// (���Ԃ�012534�ɂȂ��Ă����琬��)
			it = m_List->GetBegin();
			RecordData itData = *it;
			EXPECT_EQ(0, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(1, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(5, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(3, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(4, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		ConstIterator���w�肵�đ}���������ۂ̋����e�X�g
			@details	ID:���X�g-13\n
						TRUE�Ő���\n
						�i�[�ς݂̗v�f�ɉe�����Ȃ����A���҂����ʒu�ɗv�f���i�[����Ă��邩�B\n
						�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_0_13_Test_Insert_Const)
		{
			// ���̃f�[�^�̃X�R�A����01234
			// �擪�ɑ}��
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetBegin();

				// �擪�ɂT��}��
				m_List->Insert(it, g_data[5]);

				// ���Ԃ�501234�ɂȂ��Ă��琬��
				it = m_List->GetBegin();
				RecordData itData = *it;
				EXPECT_EQ(5, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(0, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(1, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(2, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(3, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(4, itData.m_score);
			}

			// 3�Ԗڂɑ}��
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetBegin();
				++it;
				++it;
				// �擪����3�ԖڂɂU��}��
				m_List->Insert(it, g_data[6]);
				// ���Ԃ�5061234�ɂȂ��Ă���TRUE
				it = m_List->GetBegin();
				RecordData itData = *it;
				EXPECT_EQ(5, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(0, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(6, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(1, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(2, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(3, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(4, itData.m_score);
			}

			// �����ɑ}��
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetEnd();
				// �����ɂV��}��
				m_List->Insert(it, g_data[7]);
				// ���Ԃ�5061234�ɂȂ��Ă���TRUE
				it = m_List->GetBegin();
				RecordData itData = *it;
				EXPECT_EQ(5, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(0, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(6, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(1, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(2, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(3, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(4, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(7, itData.m_score);
			}
		}

		/**********************************************************************************//**
			@brief		�s���ȃC�e���[�^��n���āA�}�������ꍇ�̋����e�X�g
			@details	ID:���X�g-14\n
						���X�g�̎Q�Ƃ������C�e���[�^��n�����ۂ̋����Ȃ�\n
						�����N����Ȃ���ΐ���\n
						2�̋�̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(TwoEmptyListTest, ID_0_14_Test_Insert_Unknown)
		{
			// ��̋�̃��X�g�ɗv�f���ЂƂ}�����Ă���
			m_List->PushBack(g_data[0]);
			m_List_2->PushBack(g_data[0]);

			// ���X�g�̎Q�Ƃ������C�e���[�^��}�������Ƃ�
			DoublyLinkedList<RecordData>::Iterator it;
			m_List->Insert(it, g_data[2]);
			//�f�[�^�����ς���Ă��Ȃ���ΐ���
			EXPECT_EQ(1, (m_List->GetDataNum()));

			// ���X�g�Q�̃C�e���[�^�����X�g�P�ɓn���đ}�������Ƃ�(�ʂ̃��X�g���Q�Ƃ����Ƃ�)
			it = m_List_2->GetBegin();
			m_List->Insert(it, g_data[2]);
			//�f�[�^�����ς���Ă��Ȃ���ΐ���
			EXPECT_EQ(1, (m_List->GetDataNum()));
		}

		// 15�̓}�j���A���e�X�g

		//=================================== �f�[�^�̍폜 ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�폜���s�����ۂ̋���
			@details	ID:���X�g-16\n
						FALSE�Ő���\n
						�擪�C�e���[�^�A�����C�e���[�^�������œn�����ꍇ�ɂ��āA�ʂɋ������`�F�b�N���邱��\n
		*//***********************************************************************************/
		TEST_F(EmptyListTest, ID_0_16_Test_Remove_Empty)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
			EXPECT_FALSE(m_List->Remove(it));

			it = m_List->GetEnd();
			EXPECT_FALSE(m_List->Remove(it));
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�폜�����ۂ̋���
			@details	ID:���X�g-17\n
						�擪�v�f�̍폜\n
						TRUE�Ő���\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_0_17_Test_Remove_Begin)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
			m_List->Remove(it);

			// �擪�v�f���Ȃ��Ȃ��Ă���ΐ���
			// ���̃f�[�^����01234�Ȃ̂ŁA1234�ɂȂ��Ă���ΐ���
			it = m_List->GetBegin();
			RecordData itData = *it;
			EXPECT_EQ(1, (itData.m_score));
			itData = *(++it);
			EXPECT_EQ(2, (itData.m_score));
			itData = *(++it);
			EXPECT_EQ(3, (itData.m_score));
			itData = *(++it);
			EXPECT_EQ(4, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�폜�����ۂ̋���
			@details	ID:���X�g-18\n
						�v�f�����ς��Ȃ����false�Ő���\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_0_18_Test_Remove_End)
		{
			int oldNum = m_List->GetDataNum();

			DoublyLinkedList<RecordData>::Iterator it = m_List->GetEnd();
			m_List->Remove(it);

			//�v�f�����ς���Ă��Ȃ���ΐ���
			EXPECT_FALSE((oldNum != m_List->GetDataNum())) << oldNum << m_List->GetDataNum();
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���č폜�����ۂ̋���
			@details	ID:���X�g-19\n
						�i�[�ς݂̗v�f�ɉe�����Ȃ����A���҂����ʒu�ɗv�f���i�[����Ă��邩\n
						TRUE�Ő���\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_0_19_TestRemoveOther)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();

			// 2�Ԗڂ��폜
			m_List->Remove(++it);

			it = m_List->GetBegin();
			RecordData itData = *it;

			// ���̃f�[�^����01234�Ȃ̂ŁA0234�ɂȂ��Ă���ΐ���
			EXPECT_EQ(0, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(3, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(4, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		ConstIterator���w�肵�č폜���s�����ۂ̋���
			@details	ID:���X�g-20\n
						�i�[�ς݂̗v�f�ɉe�����Ȃ����A���҂����ʒu�ɗv�f���i�[����Ă��邩\n
						TRUE�Ő���\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_0_20_Test_Remove_Other_Const)
		{
			// ���̃f�[�^�̃X�R�A����01234
			// �擪���폜
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCBegin();
				m_List->Remove(it);

				it = m_List->GetBegin();
				RecordData itData = *it;

				//���Ԃ�1234�ɂȂ��Ă���ΐ���
				EXPECT_EQ(1, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(2, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(3, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(4, itData.m_score);
			}

			// �擪����2�Ԗڂ��폜
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCBegin();
				m_List->Remove(++it);

				it = m_List->GetBegin();
				RecordData itData = *it;

				//���Ԃ�134�ɂȂ��Ă���ΐ���
				EXPECT_EQ(1, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(3, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(4, itData.m_score);
			}

			// �������폜
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCEnd();
				m_List->Remove(it);

				it = m_List->GetBegin();
				RecordData itData = *it;

				//���Ԃ�13�ɂȂ��Ă���ΐ���
				EXPECT_EQ(1, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(3, itData.m_score);
			}
		}
		/**********************************************************************************//**
			@brief		�s���ȃC�e���[�^��n���āA�폜�����ꍇ�̋���
			@details	ID:���X�g-21\n
						���X�g�̎Q�Ƃ��Ȃ��C�e���[�^�A�ʃ��X�g�̗v�f���w���C�e���[�^��n�����ۂ̋����Ȃ�\n
						�����N����Ȃ�\n
						FALSE�Ő���\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_0_21_Test_Remove_Unknown)
		{
			int oldNum = m_List->GetDataNum();

			// �Q�Ƃ̖����C�e���[�^��n�����Ƃ�
			{
				DoublyLinkedList<RecordData>::Iterator it;
				m_List->Remove(it);
				//�f�[�^�̑������ς���Ă��Ȃ���ΐ���
				EXPECT_EQ(oldNum, m_List->GetDataNum());
			}

			// �ʂ̃��X�g�̃C�e���[�^��n�����Ƃ�
			{
				DoublyLinkedList<RecordData> list2;
				list2.PushBack(g_data[0]);
				DoublyLinkedList<RecordData>::Iterator it = list2.GetBegin();
				m_List->Remove(it);
				//�f�[�^�̑������ς���Ă��Ȃ���ΐ���
				EXPECT_EQ(oldNum, m_List->GetDataNum());
			}
		}

		// 22�̓}�j���A���e�X�g


		//=================================== �擪�C�e���[�^�̎擾 ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-23\n
						�_�~�[�m�[�h���w���C�e���[�^���Ԃ�\n
						�f�[�^����̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(EmptyListTest, ID_0_23_Test_GetBegin_Empty)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();

			// �C�e���[�^�̎w���m�[�h���_�~�[�m�[�h���𔻕�
			EXPECT_TRUE(it.CheckDummyNode());
		}

		/**********************************************************************************//**
			@brief		���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-24\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(OneDataListTest, ID_0_24_Test_GetBegin_One)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();

			RecordData itData = *it;

			EXPECT_EQ(0, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-25\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_0_25_Test_GetBegin_Any)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();

			RecordData itData = *it;

			EXPECT_EQ(0, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-26\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(OneDataListTest, ID_0_26_Test_GetBegin_AfterInsert)
		{
			// ����������Ă���f�[�^���m�F
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
				RecordData itData = *it;
				//0�������Ă���ΐ���
				EXPECT_EQ(0, (itData.m_score));
			}

			//�擪�ɑ}��������̊m�F
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
				m_List->Insert(it, g_data[1]);
				it = m_List->GetBegin();
				RecordData itData = *it;
				//�擪��1�������Ă����OK
				EXPECT_EQ(1, (itData.m_score));
			}

			//�擪����2�Ԗڂɑ}��������̊m�F
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
				++it;
				m_List->Insert(it, g_data[2]);
				it = m_List->GetBegin();
				RecordData itData = *it;
				//�擪��1�����̂܂ܓ����Ă����OK
				EXPECT_EQ(1, (itData.m_score));
			}

			//�����ɑ}��������̊m�F
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->GetEnd();
				m_List->Insert(it, g_data[3]);
				it = m_List->GetBegin();
				RecordData itData = *it;
				//�擪��1�����̂܂ܓ����Ă����OK
				EXPECT_EQ(1, (itData.m_score));
			}
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-27\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����̗v�f�̍폜���s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_0_27_Test_GetBegin_AfterRemove)
		{
			// ���̃f�[�^�̃X�R�A����01234
			// �擪�̗v�f���폜
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
				m_List->Remove(it);
				it = m_List->GetBegin();
				RecordData itData = *it;
				// �擪�̂O�������āA1�������Ă����OK
				EXPECT_EQ(1, (itData.m_score)) << (itData.m_score);
			}

			// �擪����2�Ԗڂ̗v�f���폜
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
				++it;
				m_List->Remove(it);
				it = m_List->GetBegin();
				RecordData itData = *it;
				// 1�������Ă����OK
				EXPECT_EQ(1, (itData.m_score)) << (itData.m_score);
			}

			// �����̗v�f���폜
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->GetEnd();
				m_List->Remove(it);
				it = m_List->GetBegin();
				RecordData itData = *it;
				// 1�������Ă����OK
				EXPECT_EQ(1, (itData.m_score)) << (itData.m_score);
			}
		}

		// 28�̓}�j���A���e�X�g


		//=================================== �擪�R���X�g�C�e���[�^�̎擾 ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-29\n
						�_�~�[�m�[�h���w���C�e���[�^���Ԃ�\n
						�f�[�^����̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(EmptyListTest, ID_0_29_Test_GetConstBegin_Empty)
		{
			DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCBegin();

			// �C�e���[�^�̎w���m�[�h���_�~�[�m�[�h���𔻕�
			EXPECT_TRUE(it.CheckDummyNode());
		}

		/**********************************************************************************//**
			@brief		���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-30\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(OneDataListTest, ID_0_30_Test_GetConstBegin_One)
		{
			DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCBegin();

			RecordData itData = *it;

			EXPECT_EQ(0, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-31\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_0_31_Test_GetConstBegin_Any)
		{
			DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCBegin();

			RecordData itData = *it;

			EXPECT_EQ(0, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-32\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(OneDataListTest, ID_0_32_Test_GetConstBegin_AfterInsert)
		{
			// ����������Ă���f�[�^���m�F
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCBegin();
				RecordData itData = *it;
				//0�������Ă���ΐ���
				EXPECT_EQ(0, (itData.m_score));
			}

			//�擪�ɑ}��������̊m�F
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCBegin();
				m_List->Insert(it, g_data[1]);
				it = m_List->GetBegin();
				RecordData itData = *it;
				//�擪��1�������Ă����OK
				EXPECT_EQ(1, (itData.m_score));
			}

			//�擪����2�Ԗڂɑ}��������̊m�F
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCBegin();
				++it;
				m_List->Insert(it, g_data[2]);
				it = m_List->GetBegin();
				RecordData itData = *it;
				//�擪��1�����̂܂ܓ����Ă����OK
				EXPECT_EQ(1, (itData.m_score));
			}

			//�����ɑ}��������̊m�F
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCEnd();
				m_List->Insert(it, g_data[3]);
				it = m_List->GetBegin();
				RecordData itData = *it;
				//�擪��1�����̂܂ܓ����Ă����OK
				EXPECT_EQ(1, (itData.m_score));
			}
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-33\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_0_33_Test_GetConstBegin_AfterRemove)
		{
			// ���̃f�[�^�̃X�R�A����01234
			// �擪�̗v�f���폜
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCBegin();
				m_List->Remove(it);
				it = m_List->GetBegin();
				RecordData itData = *it;
				// �擪�̂O�������āA1�������Ă����OK
				EXPECT_EQ(1, (itData.m_score)) << (itData.m_score);
			}

			// �擪����2�Ԗڂ̗v�f���폜
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCBegin();
				++it;
				m_List->Remove(it);
				it = m_List->GetBegin();
				RecordData itData = *it;
				// 1�������Ă����OK
				EXPECT_EQ(1, (itData.m_score)) << (itData.m_score);
			}

			// �����̗v�f���폜
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCEnd();
				m_List->Remove(it);
				it = m_List->GetBegin();
				RecordData itData = *it;
				// 1�������Ă����OK
				EXPECT_EQ(1, (itData.m_score)) << (itData.m_score);
			}
		}

		// 34�̓}�j���A���e�X�g


		//=================================== �����C�e���[�^�̎擾 ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-35\n
						�_�~�[�m�[�h���w���C�e���[�^���Ԃ�\n
						�f�[�^����̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(EmptyListTest, ID_0_35_Test_GetEnd_Empty)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetEnd();

			// �C�e���[�^�̎w���m�[�h���_�~�[�m�[�h���𔻕�
			EXPECT_TRUE(it.CheckDummyNode());
		}

		/**********************************************************************************//**
			@brief		���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-36\n
						�����v�f���w���C�e���[�^���Ԃ�\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(OneDataListTest, ID_0_36_Test_GetEnd_One)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetEnd();

			// �����C�e���[�^�̑O�̗v�f���ŏ��ɓ��ꂽ�l�ł������琬��
			RecordData itData = *(--it);
			EXPECT_EQ(0, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-37\n
						�����v�f���w���C�e���[�^���Ԃ�\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_0_37_Test_GetEnd_Any)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetEnd();

			// ���̃f�[�^�̃X�R�A����01234�Ȃ̂�
			// �����C�e���[�^�̑O�̗v�f��4�ł������琬��
			RecordData itData = *(--it);
			EXPECT_EQ(4, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-38\n
						�����v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(OneDataListTest, ID_0_38_Test_GetEnd_AfterInsert)
		{
			// ����������Ă���f�[�^���m�F
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->GetEnd();
				RecordData itData = *(--it);
				EXPECT_EQ(0, (itData.m_score)); // �����̑O�v�f�f�[�^�̃X�R�A��0�������琬��
			}

			// �擪�ɑ}��
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
				m_List->Insert(it, g_data[1]);
				it = m_List->GetEnd();
				RecordData itData = *(--it);
				EXPECT_EQ(0, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��0�������琬��
			}

			// 2�Ԗڂɑ}��
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
				++it;
				m_List->Insert(it, g_data[2]);
				it = m_List->GetEnd();
				RecordData itData = *(--it);
				EXPECT_EQ(0, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��0�̂܂܂������琬��
			}
			
			// �����ɑ}��
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->GetEnd();
				m_List->Insert(it, g_data[3]);
				it = m_List->GetEnd();
				RecordData itData = *(--it);
				EXPECT_EQ(3, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��3�������琬��
			}
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-39\n
						�����v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����ɍ폜���s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_0_39_Test_GetEnd_AfterRemove)
		{
			// ���̃f�[�^���̃X�R�A����01234
			// �擪�̗v�f���폜
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
				m_List->Remove(it);
				it = m_List->GetEnd();
				RecordData itData = *(--it);
				EXPECT_EQ(4, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��4�������琬��
			}

			// �擪����2�Ԗڂ̗v�f���폜
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
				m_List->Remove(++it);
				it = m_List->GetEnd();
				RecordData itData = *(--it);
				EXPECT_EQ(4, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��4�������琬��
			}

			// �����C�e���[�^�̗v�f���폜
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->GetEnd();
				m_List->Remove(it);
				it = m_List->GetEnd();
				RecordData itData = *(--it);
				EXPECT_EQ(4, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��4�������琬��
				// �����C�e���[�^�̓_�~�[�m�[�h�Ȃ̂ŕς��Ȃ�
			}

			// �����C�e���[�^�̂ЂƂO�̗v�f���폜
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->GetEnd();
				m_List->Remove(--it);
				it = m_List->GetEnd();
				RecordData itData = *(--it);
				EXPECT_EQ(3, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��3�������琬��
			}
		}

		//40�̓}�j���A���e�X�g


		//=================================== �����R���X�g�C�e���[�^�̎擾 ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-41\n
						�_�~�[�m�[�h���w���C�e���[�^���Ԃ�\n
						�f�[�^����̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(EmptyListTest, ID_0_41_Test_GetConstEnd_Empty)
		{
			DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCEnd();

			// �C�e���[�^�̎w���m�[�h���_�~�[�m�[�h���𔻕�
			EXPECT_TRUE(it.CheckDummyNode());
		}

		/**********************************************************************************//**
			@brief		���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-42\n
						�����v�f���w���C�e���[�^���Ԃ�\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(OneDataListTest, ID_0_42_Test_GetConstEnd_One)
		{
			DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCEnd();

			// �����C�e���[�^�̑O�̗v�f���ŏ��ɓ��ꂽ�l�ł������琬��
			RecordData itData = *(--it);
			EXPECT_EQ(0, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-43\n
						�����v�f���w���C�e���[�^���Ԃ�\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_0_43_Test_GetConstEnd_Any)
		{
			DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCEnd();

			// ���̃f�[�^�̃X�R�A����01234�Ȃ̂�
			// �����C�e���[�^�̑O�̗v�f��4�ł������琬��
			RecordData itData = *(--it);
			EXPECT_EQ(4, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-44\n
						�����v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(OneDataListTest, ID_0_44_Test_GetConstEnd_AfterInsert)
		{
			// ����������Ă���f�[�^���m�F
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCEnd();
				RecordData itData = *(--it);
				EXPECT_EQ(0, (itData.m_score)); // �����̑O�v�f�f�[�^�̃X�R�A��0�������琬��
			}

			// �擪�ɑ}��
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCBegin();
				m_List->Insert(it, g_data[1]);
				it = m_List->GetCEnd();
				RecordData itData = *(--it);
				EXPECT_EQ(0, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��0�������琬��
			}

			// 2�Ԗڂɑ}��
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCBegin();
				++it;
				m_List->Insert(it, g_data[2]);
				it = m_List->GetCEnd();
				RecordData itData = *(--it);
				EXPECT_EQ(0, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��0�̂܂܂������琬��
			}

			// �����ɑ}��
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCEnd();
				m_List->Insert(it, g_data[3]);
				it = m_List->GetCEnd();
				RecordData itData = *(--it);
				EXPECT_EQ(3, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��3�������琬��
			}
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-45\n
						�����v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_0_45_Test_GetConstEnd_AfterRemove)
		{
			// ���̃f�[�^���̃X�R�A����01234
			// �擪�̗v�f���폜
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCEnd();
				m_List->Remove(it);
				it = m_List->GetCEnd();
				RecordData itData = *(--it);
				EXPECT_EQ(4, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��4�������琬��
			}

			// �擪����2�Ԗڂ̗v�f���폜
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCBegin();
				m_List->Remove(++it);
				it = m_List->GetCEnd();
				RecordData itData = *(--it);
				EXPECT_EQ(4, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��4�������琬��
			}

			// �����C�e���[�^�̗v�f���폜
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCEnd();
				m_List->Remove(it);
				it = m_List->GetCEnd();
				RecordData itData = *(--it);
				EXPECT_EQ(4, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��4�������琬��
				// �����C�e���[�^�̓_�~�[�m�[�h�Ȃ̂ŕς��Ȃ�
			}

			// �����C�e���[�^�̂ЂƂO�̗v�f���폜
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->GetCEnd();
				m_List->Remove(--it);
				it = m_List->GetCEnd();
				RecordData itData = *(--it);
				EXPECT_EQ(3, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��3�������琬��
			}
		}

		//46�̓}�j���A���e�X�g
	}

	//=====================================================================================================
	//=====================================================================================================
	//=====================================================================================================

	namespace chapter2
	{
		//===================================�C�e���[�^�̎w���v�f�̎擾 ===================================

		/**********************************************************************************//**
			@brief		���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
			@details	ID:���X�g-0\n
						Assert����\n
						��̃��X�g���g�p\n
		*//***********************************************************************************/
#ifdef _DEBUG
		TEST_F(EmptyListTest, ID_1_0_Test_GetIt_NoReference)
		{
			DoublyLinkedList<RecordData>::Iterator it;

			EXPECT_DEATH(*it, ".*"); // ���X�g����Ȃ̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
		}
#endif //_DEBUG
		/**********************************************************************************//**
			@brief		Iterator����擾�����v�f�ɑ΂��āA�l�̑�����s���邩���`�F�b�N
			@details	ID:���X�g-1\n
						�����ɍēx�Ăяo���A�l���ύX����Ă��邱�Ƃ��m�F\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(OneDataListTest, ID_1_1_Test_GetIt_Assign)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();

			*it = g_data[1]; // �ʂ̃f�[�^����
			RecordData itData = *it;

			// �P�������Ă���ΐ���
			EXPECT_EQ(1, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
			@details	ID:���X�g-3\n
						Assert����\n
						��̃��X�g���g�p\n
		*//***********************************************************************************/
#ifdef _DEBUG
		TEST_F(EmptyListTest, ID_1_3_Test_GetIt_EmptyBegin)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();

			EXPECT_DEATH(*it, ".*"); // ���X�g����Ȃ̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
		}
#endif //_DEBUG
		/**********************************************************************************//**
			@brief		�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
			@details	ID:���X�g-4\n
						Assert����\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
#ifdef _DEBUG
		TEST_F(OneDataListTest, ID_1_4_Test_GetIt_EmptyEnd)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetEnd();

			EXPECT_DEATH(*it, ".*"); // �_�~�[�m�[�h���w���̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
		}
#endif //_DEBUG
		//===================================�C�e���[�^�����X�g�̖����Ɍ������ĂЂƂi�߂�===================================

		/**********************************************************************************//**
			@brief		���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
			@details	ID:���X�g-5\n
						Assert����\n
						��̃��X�g���g�p\n
		*//***********************************************************************************/
#ifdef _DEBUG
		TEST_F(EmptyListTest, ID_1_5_Test_Increment_NoReference)
		{
			DoublyLinkedList<RecordData>::Iterator it;

			EXPECT_DEATH(++it, ".*"); // ���X�g����Ȃ̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
		}
#endif //_DEBUG
		/**********************************************************************************//**
			@brief		���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
			@details	ID:���X�g-6\n
						Assert����\n
						��̃��X�g���g�p\n
		*//***********************************************************************************/
#ifdef _DEBUG
		TEST_F(EmptyListTest, ID_1_6_Test_Increment_TestEmptyBegin)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();

			EXPECT_DEATH(++it, ".*"); // ���X�g����Ȃ̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
		}
#endif //_DEBUG
		/**********************************************************************************//**
			@brief		�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
			@details	ID:���X�g-7\n
						Assert����\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
#ifdef _DEBUG
		TEST_F(OneDataListTest, ID_1_7_Test_Increment_EndIt)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetEnd();

			EXPECT_DEATH(++it, ".*"); // �_�~�[�m�[�h���w���̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
		}
#endif //_DEBUG
		/**********************************************************************************//**
			@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
			@details	ID:���X�g-8\n
						���̗v�f���w��\n
						���X�g�̐擪���疖���܂ŌĂяo�����s���A���҂���Ă���v�f���i�[����Ă��邩���m�F\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_1_8_Test_Increment_Any)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
			RecordData itData = *it;

			// 01234�ł���ΐ���
			EXPECT_EQ(0, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(1, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(3, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(4, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		�O�u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
			@details	ID:���X�g-9\n
						���̗v�f���w��\n
						�C���N�������g�Ăяo�����̒l�ƁA�C���N�������g���s��̒l�̗������m�F\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_1_9_Test_Increment_PrefIncrement)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
			RecordData itData = *it;

			// 01234�ł���ΐ���
			EXPECT_EQ(0, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(1, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(3, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(4, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		��u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
			@details	ID:���X�g-10\n
						���̗v�f���w��\n
						�C���N�������g�Ăяo�����̒l�ƁA�C���N�������g���s��̒l�̗������m�F\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_1_10_Test_Increment_BackIncrement)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
			RecordData itData = *it;

			// 00123�ł���ΐ���
			EXPECT_EQ(0, itData.m_score);
			itData = *(it++);
			EXPECT_EQ(0, itData.m_score);
			itData = *(it++);
			EXPECT_EQ(1, itData.m_score);
			itData = *(it++);
			EXPECT_EQ(2, itData.m_score);
			itData = *(it++);
			EXPECT_EQ(3, itData.m_score);
		}


		//===================================�C�e���[�^�����X�g�̐擪�Ɍ������ĂЂƂi�߂�===================================

		/**********************************************************************************//**
			@brief		���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
			@details	ID:���X�g-11\n
						Assert����\n
						��̃��X�g���g�p\n
		*//***********************************************************************************/
#ifdef _DEBUG
		TEST_F(EmptyListTest, ID_1_11_Test_Decrement_NoReference)
		{
			DoublyLinkedList<RecordData>::Iterator it;

			EXPECT_DEATH(--it, ".*"); // ���X�g�̎Q�Ƃ��Ȃ��̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
		}
#endif //_DEBUG
		/**********************************************************************************//**
			@brief		���X�g����̍ۂ́A�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
			@details	ID:���X�g-12\n
						Assert����\n
						��̃��X�g���g�p\n
		*//***********************************************************************************/
#ifdef _DEBUG
		TEST_F(EmptyListTest, ID_1_12_Test_Decrement_EmptyEnd)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetEnd();

			EXPECT_DEATH(--it, ".*"); // ���X�g����Ȃ̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
		}
#endif //_DEBUG
		/**********************************************************************************//**
			@brief		�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
			@details	ID:���X�g-13\n
						Assert����\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
#ifdef _DEBUG
		TEST_F(OneDataListTest, ID_1_13_Test_Decrement_BeginIt)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();

			EXPECT_DEATH(--it, ".*"); // �_�~�[�m�[�h���w���̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
		}
#endif //_DEBUG
		/**********************************************************************************//**
			@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
			@details	ID:���X�g-14\n
						�O�̗v�f���w��\n
						���X�g�̖�������擪�܂ŌĂяo�����s���A���҂���Ă���v�f���i�[����Ă��邩���m�F\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_1_14_Test_Decrement_Any)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetEnd();
			RecordData itData = *(--it);

			// 43210�ł���ΐ���
			EXPECT_EQ(4, itData.m_score);
			itData = *(--it);
			EXPECT_EQ(3, itData.m_score);
			itData = *(--it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(--it);
			EXPECT_EQ(1, itData.m_score);
			itData = *(--it);
			EXPECT_EQ(0, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		�O�u�f�N�������g�s�����ۂ̋���( --���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
			@details	ID:���X�g-15\n
						���̗v�f���w��\n
						�f�N�������g�Ăяo�����̒l�ƁA�f�N�������g���s��̒l�̗������m�F\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_1_15_Test_Decrement_PrefDecrement)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetEnd();
			RecordData itData = *(--it);

			// 43210�ł���ΐ���
			EXPECT_EQ(4, itData.m_score);
			itData = *(--it);
			EXPECT_EQ(3, itData.m_score);
			itData = *(--it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(--it);
			EXPECT_EQ(1, itData.m_score);
			itData = *(--it);
			EXPECT_EQ(0, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		��u�f�N�������g���s�����ۂ̋���( --���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
			@details	ID:���X�g-16\n
						���̗v�f���w��\n
						�f�N�������g�Ăяo�����̒l�ƁA�f�N�������g���s��̒l�̗������m�F\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_1_16_Test_Decrement_BackDecrement)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetEnd();
			RecordData itData = *(--it);

			// 44321�ł���ΐ���
			EXPECT_EQ(4, itData.m_score);
			itData = *(it--);
			EXPECT_EQ(4, itData.m_score);
			itData = *(it--);
			EXPECT_EQ(3, itData.m_score);
			itData = *(it--);
			EXPECT_EQ(2, itData.m_score);
			itData = *(it--);
			EXPECT_EQ(1, itData.m_score);
		}

		//17�̓}�j���A���e�X�g

		/**********************************************************************************//**
			@brief		�C�e���[�^�̃R�s�[���s��
			@details	ID:���X�g-18\n
						�R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(OneDataListTest, ID_1_18_Test_Copy_Equal)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
			DoublyLinkedList<RecordData>::Iterator it2 = it;

			RecordData itData = *it;
			RecordData itData2 = *it2;

			EXPECT_TRUE(it == it2);
			EXPECT_TRUE(itData.m_score == itData2.m_score);
		}

		//19�̓}�j���A���e�X�g

		/**********************************************************************************//**
			@brief		�C�e���[�^�̑�����s��
			@details	ID:���X�g-20\n
						�����̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_1_20_Test_Assign_Equal)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
			DoublyLinkedList<RecordData>::Iterator it2 = m_List->GetBegin();

			++it2;
			it2 = it; 

			RecordData itData = *it;
			RecordData itData2 = *it2;

			EXPECT_TRUE(it == it2);
			EXPECT_TRUE(itData.m_score == itData2.m_score);
		}


		//===================================�ӂ��̃C�e���[�^������̂��̂ł��邩��r===================================

		/**********************************************************************************//**
			@brief		���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
			@details	ID:���X�g-21\n
						TRUE�Ő���\n
						��̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(EmptyListTest, ID_1_21_Test_Equal_Empty)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
			DoublyLinkedList<RecordData>::Iterator it2 = m_List->GetEnd();

			EXPECT_TRUE(it == it2);
		}

		/**********************************************************************************//**
			@brief		����̃C�e���[�^���r�����ۂ̋���
			@details	ID:���X�g-22\n
						TRUE�Ő���\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(OneDataListTest, ID_1_22_Test_Equal_Same)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
			DoublyLinkedList<RecordData>::Iterator it2 = m_List->GetBegin();

			EXPECT_TRUE(it == it2);
		}

		/**********************************************************************************//**
			@brief		�قȂ�C�e���[�^���r�����ۂ̋���
			@details	ID:���X�g-23\n
						FALSE�Ő���\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_1_23_Test_Equal_Diff)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
			DoublyLinkedList<RecordData>::Iterator it2 = m_List->GetBegin();
			++it2;

			EXPECT_FALSE(it == it2);
		}


		//===================================�ӂ��̃C�e���[�^���قȂ���̂ł��邩��r===================================

		/**********************************************************************************//**
			@brief		���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
			@details	ID:���X�g-24\n
						��̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(EmptyListTest, ID_1_24_Test_NotEqual_Empty)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
			DoublyLinkedList<RecordData>::Iterator it2 = m_List->GetEnd();

			EXPECT_FALSE(it != it2);
		}

		/**********************************************************************************//**
			@brief		����̃C�e���[�^���r�����ۂ̋���
			@details	ID:���X�g-25\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(OneDataListTest, ID_1_25_Test_NotEqual)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
			DoublyLinkedList<RecordData>::Iterator it2 = m_List->GetBegin();

			EXPECT_FALSE(it != it2);
		}

		/**********************************************************************************//**
			@brief		�قȂ�C�e���[�^���r�����ۂ̋���
			@details	ID:���X�g-26\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(FiveDataListTest, ID_1_26_Test_NotEqual_Diff)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->GetBegin();
			DoublyLinkedList<RecordData>::Iterator it2 = m_List->GetBegin();
			it2++;

			EXPECT_TRUE(it != it2);
		}
	}
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	getchar();
	return 0;
}