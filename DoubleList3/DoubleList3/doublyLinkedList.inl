/**
* @file doublyLinkedList.inl
* @brief �o�������X�g�N���X
* @author ����P
* @date 2023/10/17/15:00
* @details �ۑ�1_3�u�o�������X�g�̃e���v���[�g���v
*/

#pragma once

#include <assert.h>
#include <string>
#include "doublyLinkedList.h"

//===============================================================
/*�o�������X�g�N���X*/

/**
* @brief �o�������X�g�N���X�̃R���X�g���N�^
* @details �f�[�^���A�_�~�[�m�[�h��������\n
		   ���X�g����̏ꍇ�A�_�~�[�m�[�h�̑O��̓_�~�[�m�[�h���g���Q��\n
*/
template<typename DATA>
inline DoublyLinkedList<DATA>::DoublyLinkedList() : m_DataNum(0)
{
	m_DummyNode = new Node();
	m_DummyNode->m_next = m_DummyNode;
	m_DummyNode->m_prev = m_DummyNode;
}

/**
* @brief �o�������X�g�N���X�̃f�X�g���N�^
* @details �擪���疖���܂�delete
*/
template<typename DATA>
inline DoublyLinkedList<DATA>::~DoublyLinkedList()
{
	Node* node = m_DummyNode->m_next;
	while (node != m_DummyNode)
	{
		Node* temp = node;
		node = node->m_next;
		delete temp;
	}
}

/**
* @brief �f�[�^���̎擾
* @return ���X�g�̃f�[�^�̑�����Ԃ�
*/
template<typename DATA>
inline int DoublyLinkedList<DATA>::GetDataNum() const
{
	return m_DataNum;
}

/**
* @brief �f�[�^�̑}��
* @param[in] it �}���������ʒu�̃C�e���[�^
* @param[in] data �}�����������уf�[�^
* @return bool(�}�������������true�A���s�����false)
* @details �C�e���[�^�̎w���m�[�h�̑O�ɑ}������
*/
template<typename DATA>
inline bool DoublyLinkedList<DATA>::Insert(ConstIterator & it, const DATA & data)
{
	if (it.m_List != this) return false; // �C�e���[�^���ʂ̃��X�g�̗v�f���w���C�e���[�^�ł�������return

	Node* newNode = new Node(data); // �V�m�[�h

	Node* itNode = it.m_Node; // �C�e���[�^�̎w���m�[�h

	// �V�m�[�h�̑O�m�[�h���C�e���[�^�̎w���O�m�[�h�ɁB
	newNode->m_prev = itNode->m_prev;

	// �V�m�[�h�̎��m�[�h���C�e���[�^�̎w���m�[�h�ɁB
	newNode->m_next = itNode;

	// �C�e���[�^�̎w���m�[�h�̑O�m�[�h�̎��̃m�[�h�ɐV�m�[�h���i�[
	// (�C�e���[�^�m�[�h�ƑO�m�[�h�̊ԂɊi�[)
	itNode->m_prev->m_next = newNode;

	// �C�e���[�^�̎w���m�[�h�̑O�m�[�h�ɐV�m�[�h���i�[�A����Ńf�[�^���q����
	itNode->m_prev = newNode;

	// �f�[�^���𑝂₷
	m_DataNum++;

	return true;
}

/**
* @brief �f�[�^�̒ǉ�
* @param[in] data �ǉ����������уf�[�^
* @details �����Ƀf�[�^�̒ǉ�
*/
template<typename DATA>
inline void DoublyLinkedList<DATA>::PushBack(const DATA & data)
{
	DoublyLinkedList<DATA>::ConstIterator endIt = GetCEnd();
	Insert(endIt, data);
}

/**
* @brief �f�[�^�̍폜
* @param[in] it �폜�������ʒu�̃C�e���[�^
* @return �폜�Ɏ��s������false�A����������true��Ԃ�
* @details �C�e���[�^�̎w���m�[�h���폜\n
			�f�[�^����0�A�C�e���[�^�̎w���m�[�h���_�~�[�m�[�h�A�ʃ��X�g���w���C�e���[�^�ł���Ή����s��Ȃ�\n
*/
template<typename DATA>
inline bool DoublyLinkedList<DATA>::Remove(ConstIterator & it)
{
	Node* itNode = it.m_Node; // �C�e���[�^�̎w���m�[�h
	if (m_DataNum == 0) return false;
	if (itNode == m_DummyNode) return false;
	if (it.m_List != this) return false; // �C�e���[�^���ʂ̃��X�g�̗v�f���w���C�e���[�^�ł�������return


	itNode->m_prev->m_next = itNode->m_next;
	itNode->m_next->m_prev = itNode->m_prev;

	delete itNode;
	m_DataNum--;
	return true;
}

/**
* @brief �擪�C�e���[�^�擾
* @return �_�~�[�m�[�h�̎��̃m�[�h(�擪�̃C�e���[�^��Ԃ�)
*/
template<typename DATA>
inline typename DoublyLinkedList<DATA>::Iterator DoublyLinkedList<DATA>::GetBegin()
{
	return Iterator(m_DummyNode->m_next, this);
}

/**
* @brief �擪�R���X�g�C�e���[�^�擾
* @return �_�~�[�m�[�h�̎��̃m�[�h(�擪�̃R���X�g�C�e���[�^��Ԃ�)
*/
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator DoublyLinkedList<DATA>::GetCBegin() const
{
	return ConstIterator(m_DummyNode->m_next, this);
}

/**
* @brief �����C�e���[�^�擾
* @return �_�~�[�m�[�h��Ԃ�
*/
template<typename DATA>
inline typename DoublyLinkedList<DATA>::Iterator DoublyLinkedList<DATA>::GetEnd()
{
	return Iterator(m_DummyNode, this);
}

/**
* @brief �����R���X�g�C�e���[�^�擾
* @return �_�~�[�m�[�h��Ԃ�
*/
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator DoublyLinkedList<DATA>::GetCEnd() const
{
	return ConstIterator(m_DummyNode, this);
}




//===============================================================
/*�R���X�g�C�e���[�^*/

/**
* @brief ���������R���X�g���N�^
*/
template<typename DATA>
inline DoublyLinkedList<DATA>::ConstIterator::ConstIterator() : m_Node(nullptr), m_List(nullptr) {}

/**
* @brief �����t���R���X�g���N�^
* @param[in] node �C�e���[�^�̎w���v�f
* @param[in] list ���X�g�̎Q��
*/
template<typename DATA>
inline DoublyLinkedList<DATA>::ConstIterator::ConstIterator(Node * node, const DoublyLinkedList* list) : m_Node(node), m_List(list) {}

/**
* @brief �R�s�[�R���X�g���N�^
* @param[in] it �R�s�[���̃R���X�g�C�e���[�^
*/
template<typename DATA>
inline DoublyLinkedList<DATA>::ConstIterator::ConstIterator(const ConstIterator& it) : m_Node(it.m_Node), m_List(it.m_List) {}

/**
* @brief �C�e���[�^�̐擪�Ɍ������ĂЂƂi�߂�(�O�u)
* @return �擪�ɂЂƂi�߂��C�e���[�^��Ԃ�
* @details �m�[�h�̎Q�Ƃ�����������or�_�~�[�m�[�h�ł�������assert
*/
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator& DoublyLinkedList<DATA>::ConstIterator::operator--()
{
	assert(this->m_Node != nullptr);
	assert(this->m_Node != m_List->m_DummyNode->m_next);
	m_Node = m_Node->m_prev;
	return *this;
}

/**
* @brief �C�e���[�^�̐擪�Ɍ������ĂЂƂi�߂�(��u)
* @return �擪�ɂЂƂi�߂��C�e���[�^��Ԃ�
* @details �m�[�h�̎Q�Ƃ�����������or�_�~�[�m�[�h�ł�������assert
*/
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator DoublyLinkedList<DATA>::ConstIterator::operator--(int)
{
	assert(this->m_Node != nullptr);
	assert(this->m_Node != m_List->m_DummyNode->m_next);
	ConstIterator ci = *this;
	m_Node = m_Node->m_prev;
	return ci;
}

/**
* @brief �C�e���[�^�̖����Ɍ������ĂЂƂi�߂�(�O�u)
* @return �����ɂЂƂi�߂��C�e���[�^��Ԃ�
* @details �m�[�h�̎Q�Ƃ�����������or�_�~�[�m�[�h�ł�������assert
*/
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator& DoublyLinkedList<DATA>::ConstIterator::operator++()
{
	assert(this->m_Node != nullptr);
	assert(this->m_Node != m_List->m_DummyNode);
	m_Node = m_Node->m_next;
	return *this;
}

/**
* @brief �C�e���[�^�̖����Ɍ������ĂЂƂi�߂�(��u)
* @return �����ɂЂƂi�߂��C�e���[�^��Ԃ�
* @details �m�[�h�̎Q�Ƃ�����������or�_�~�[�m�[�h�ł�������assert
*/
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator DoublyLinkedList<DATA>::ConstIterator::operator++(int)
{
	assert(this->m_Node != nullptr);
	assert(this->m_Node != m_List->m_DummyNode);
	ConstIterator ci = *this;
	m_Node = m_Node->m_next;
	return ci;
}

/**
* @brief �C�e���[�^�̎w���v�f���擾����(const)
* @return �C�e���[�^�̎w�����уf�[�^��Ԃ�
* @details �m�[�h�̎Q�Ƃ�����������or�_�~�[�m�[�h�ł�������assert
*/
template<typename DATA>
inline const DATA DoublyLinkedList<DATA>::ConstIterator::operator*() const
{
	assert(this->m_Node != nullptr);
	assert(this->m_Node != m_List->m_DummyNode);
	return this->m_Node->m_data;
}

/**
* @brief ������s��
* @param[in] it �������C�e���[�^
* @details �C�e���[�^�̃m�[�h��������
*/
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator& DoublyLinkedList<DATA>::ConstIterator::operator=(const ConstIterator & it)
{
	m_Node = it.m_Node;
	return *this;
}

/**
* @brief ���ꂩ��r����
* @param[in] it ���ꂩ��r����C�e���[�^
* @return �C�e���[�^�̎w���v�f������ł����true��Ԃ�
*/
template<typename DATA>
inline bool DoublyLinkedList<DATA>::ConstIterator::operator==(const ConstIterator & it)
{
	return (m_Node == it.m_Node);
}

/**
* @brief �قȂ邩��r����
* @param[in] it �قȂ邩��r����C�e���[�^
* @return �C�e���[�^�̎w���v�f���قȂ��true��Ԃ�
*/
template<typename DATA>
inline bool DoublyLinkedList<DATA>::ConstIterator::operator!=(const ConstIterator & it)
{
	return (m_Node != it.m_Node);
}

/**
* @brief �C�e���[�^�̎w���m�[�h���_�~�[�m�[�h�����ʂ���
* @return �����_�~�[�m�[�h�ł����true��Ԃ�
* @details �e�X�g�Ń_�~�[�m�[�h�Ɣ�r����ۂɎg�p
*/
template<typename DATA>
inline bool DoublyLinkedList<DATA>::ConstIterator::CheckDummyNode()
{
	if (this->m_Node == m_List->m_DummyNode)
		return true;
	else
		return false;
}

//===============================================================
/*�C�e���[�^*/
/**
* @brief ���������R���X�g���N�^
*/
template<typename DATA>
inline DoublyLinkedList<DATA>::Iterator::Iterator() : ConstIterator() {}

/**
* @brief �����t���R���X�g���N�^
* @param[in] node �C�e���[�^�̎w���v�f
* @param[in] list ���X�g�̎Q��
*/
template<typename DATA>
inline DoublyLinkedList<DATA>::Iterator::Iterator(Node * node, const DoublyLinkedList* list) : ConstIterator(node, list) {}

/**
* @brief �C�e���[�^�̎w���v�f���擾����(��const)
* @return �C�e���[�^�̎w�����уf�[�^��Ԃ�
* @details �m�[�h�̎Q�Ƃ�����������or�_�~�[�m�[�h�ł�������assert
*/
template<typename DATA>
inline DATA & DoublyLinkedList<DATA>::Iterator::operator*()
{
	assert(this->m_Node != nullptr);
	assert(this->m_Node != this->m_List->m_DummyNode);
	return this->m_Node->m_data;
}
