/**
* @file doublyLinkedList.h
* @brief �o�������X�g�N���X
* @author ����P
* @date 2023/10/17/15:00
* @details �ۑ�1_3�u�o�������X�g�̃e���v���[�g���v
*/

#pragma once

/**
* @brief �o�������X�g�N���X
*/
template<typename DATA>
class DoublyLinkedList
{
private:
	/**
	* @brief �m�[�h
	*/
	struct Node
	{
		//! �O�m�[�h
		Node* m_prev;

		//! ���m�[�h
		Node* m_next;

		//! �f�[�^
		DATA m_data;

		/**
		* @brief ���������R���X�g���N�^
		*/
		Node() : m_prev(nullptr), m_next(nullptr), m_data() {}

		/**
		* @brief �����t���R���X�g���N�^
		* @param[in] data �v�f�����f�[�^
		*/
		Node(const DATA data) : m_prev(nullptr), m_next(nullptr), m_data(data) {}
	};

	//! �_�~�[�m�[�h
	Node* m_DummyNode;

	//! �f�[�^��
	int m_DataNum;

public:

	/**
	* @brief �R���X�g�C�e���[�^�N���X
	* @details �o�������X�g�N���X�̃C���i�[�N���X
	*/
	class ConstIterator
	{
	private:
		//! �o�������X�g�N���X��friend�w��
		friend class DoublyLinkedList;

		//! �m�[�h�ւ̃|�C���^
		Node* m_Node;

		//! ���X�g�̃|�C���^
		const DoublyLinkedList* m_List;

	public:

		/**
		* @brief ���������R���X�g���N�^
		*/
		inline ConstIterator();

		/**
		* @brief �����t���R���X�g���N�^
		* @param[in] node �C�e���[�^�̎w���v�f
		* @param[in] list ���X�g�̎Q��
		*/
		inline ConstIterator(Node* node, const DoublyLinkedList* list);

		/**
		* @brief �C�e���[�^�̐擪�Ɍ������ĂЂƂi�߂�(�O�u)
		* @return �擪�ɂЂƂi�߂��C�e���[�^��Ԃ�
		* @details �m�[�h�̎Q�Ƃ�����������or�_�~�[�m�[�h�ł�������assert
		*/
		inline ConstIterator& operator--();

		/**
		* @brief �C�e���[�^�̐擪�Ɍ������ĂЂƂi�߂�(��u)
		* @return �擪�ɂЂƂi�߂��C�e���[�^��Ԃ�
		* @details �m�[�h�̎Q�Ƃ�����������or�_�~�[�m�[�h�ł�������assert
		*/
		inline ConstIterator operator--(int);

		/**
		* @brief �C�e���[�^�̖����Ɍ������ĂЂƂi�߂�(�O�u)
		* @return �����ɂЂƂi�߂��C�e���[�^��Ԃ�
		* @details �m�[�h�̎Q�Ƃ�����������or�_�~�[�m�[�h�ł�������assert
		*/
		inline ConstIterator& operator++();

		/**
		* @brief �C�e���[�^�̖����Ɍ������ĂЂƂi�߂�(��u)
		* @return �����ɂЂƂi�߂��C�e���[�^��Ԃ�
		* @details �m�[�h�̎Q�Ƃ�����������or�_�~�[�m�[�h�ł�������assert
		*/
		inline ConstIterator operator++(int);

		/**
		* @brief �C�e���[�^�̎w���v�f���擾����(const)
		* @return �C�e���[�^�̎w�����уf�[�^��Ԃ�
		* @details �m�[�h�̎Q�Ƃ�����������or�_�~�[�m�[�h�ł�������assert
		*/
		inline const DATA operator*() const;

		/**
		* @brief �R�s�[�R���X�g���N�^
		* @param[in] it �R�s�[���̃R���X�g�C�e���[�^
		*/
		inline ConstIterator(const ConstIterator& it);

		/**
		* @brief ������s��
		* @param[in] it �������C�e���[�^
		* @details �C�e���[�^�̃m�[�h��������
		*/
		inline ConstIterator& operator=(const ConstIterator& it);

		/**
		* @brief ���ꂩ��r����
		* @param[in] it ���ꂩ��r����C�e���[�^
		* @return �C�e���[�^�̎w���v�f������ł����true��Ԃ�
		*/
		inline bool operator==(const ConstIterator& it);

		/**
		* @brief �قȂ邩��r����
		* @param[in] it �قȂ邩��r����C�e���[�^
		* @return �C�e���[�^�̎w���v�f���قȂ��true��Ԃ�
		*/
		inline bool operator!=(const ConstIterator& it);

		/**
		* @brief �C�e���[�^�̎w���m�[�h���_�~�[�m�[�h�����ʂ���
		* @return �����_�~�[�m�[�h�ł����true��Ԃ�
		* @details �e�X�g�Ń_�~�[�m�[�h�Ɣ�r����ۂɎg�p
		*/
		inline bool CheckDummyNode();
	};

	/**
	* @brief �C�e���[�^�N���X
	* @details �R���X�g�C�e���[�^�N���X�̔h���N���X
	*/
	class Iterator : public ConstIterator
	{
	public:
		/**
		* @brief ���������R���X�g���N�^
		*/
		inline Iterator();

		/**
		* @brief �����t���R���X�g���N�^
		* @param[in] node �C�e���[�^�̎w���v�f
		* @param[in] list ���X�g�̎Q��
		*/
		inline Iterator(Node* node, const DoublyLinkedList* list);

		/**
		* @brief �C�e���[�^�̎w���v�f���擾����(��const)
		* @return �C�e���[�^�̎w�����уf�[�^��Ԃ�
		* @details �m�[�h�̎Q�Ƃ�����������or�_�~�[�m�[�h�ł�������assert
		*/
		inline DATA& operator*();
	};

	/**
	* @brief �o�������X�g�N���X�̃R���X�g���N�^
	* @details �f�[�^���A�_�~�[�m�[�h��������\n
			   ���X�g����̏ꍇ�A�_�~�[�m�[�h�̑O��̓_�~�[�m�[�h���g���Q��\n
	*/
	inline DoublyLinkedList();

	/**
	* @brief �o�������X�g�N���X�̃f�X�g���N�^
	* @details �擪���疖���܂�delete
	*/
	virtual inline ~DoublyLinkedList();

	/**
	* @brief �f�[�^���̎擾
	* @return ���X�g�̃f�[�^�̑�����Ԃ�
	*/
	inline int GetDataNum() const;

	/**
	* @brief �f�[�^�̑}��
	* @param[in] it �}���������ʒu�̃C�e���[�^
	* @param[in] data �}�����������уf�[�^
	* @return bool(�}�������������true�A���s�����false)
	* @details �C�e���[�^�̎w���m�[�h�̑O�ɑ}������
	*/
	inline bool Insert(ConstIterator& it, const DATA& data);

	/**
	* @brief �f�[�^�̒ǉ�
	* @param[in] data �ǉ����������уf�[�^
	* @details �����Ƀf�[�^�̒ǉ�
	*/
	inline void PushBack(const DATA& data);

	/**
	* @brief �f�[�^�̍폜
	* @param[in] it �폜�������ʒu�̃C�e���[�^
	* @return �폜�Ɏ��s������false�A����������true��Ԃ�
	* @details �C�e���[�^�̎w���m�[�h���폜\n
				�f�[�^����0�A�C�e���[�^�̎w���m�[�h���_�~�[�m�[�h�A�ʃ��X�g���w���C�e���[�^�ł���Ή����s��Ȃ�\n
	*/
	inline bool Remove(ConstIterator& it);

	/**
	* @brief �擪�C�e���[�^�擾
	* @return �_�~�[�m�[�h�̎��̃m�[�h(�擪�̃C�e���[�^��Ԃ�)
	*/
	inline Iterator GetBegin();

	/**
	* @brief �擪�R���X�g�C�e���[�^�擾
	* @return �_�~�[�m�[�h�̎��̃m�[�h(�擪�̃R���X�g�C�e���[�^��Ԃ�)
	*/
	inline ConstIterator GetCBegin() const;

	/**
	* @brief �����C�e���[�^�擾
	* @return �_�~�[�m�[�h��Ԃ�
	*/
	inline Iterator GetEnd();

	/**
	* @brief �����R���X�g�C�e���[�^�擾
	* @return �_�~�[�m�[�h��Ԃ�
	*/
	inline ConstIterator GetCEnd() const;
};

#include "doublyLinkedList.inl"
