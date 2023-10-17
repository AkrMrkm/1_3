/**
* @file main.cpp
* @brief �o�������X�g�N���X
* @author ����P
* @date 2023/10/17/15:00
* @details �ۑ�1_3�u�o�������X�g�̃e���v���[�g���v
*/

#include <iostream>
#include <fstream>
#include <string>
#include "doublyLinkedList.h"

// ���уf�[�^
struct RecordData
{
	int m_score; // �X�R�A
	std::string m_name; // ���O
};

int main()
{
	std::ifstream inputFile("Scores.txt"); //�t�@�C���ǂݍ���

	if (!inputFile.is_open()) // �t�@�C�����J���Ȃ�������I��
	{
		std::cerr << "�t�@�C�����J���܂���B" << std::endl;
		getchar();
		return 0;
	}

	DoublyLinkedList<RecordData> list;

	// �t�@�C������ǂݍ��񂾒l���i�[����ϐ�
	int score;
	std::string name;

	// �t�@�C������f�[�^��ǂݍ���Ń��X�g�ɒǉ�
	while (inputFile >> score >> name)
	{
		RecordData data = { score,name };
		list.PushBack(data);
	}

	// �t�@�C�������
	inputFile.close();

	// ���X�g���i�[�������ŕ\��
	DoublyLinkedList<RecordData>::Iterator it = list.GetBegin();
	RecordData data;
	auto endIt = list.GetCEnd();
	for (auto it = list.GetCBegin(); it != endIt; ++it)
	{
		data = *it;
		std::cout << " score : " << data.m_score << "   name : " << data.m_name << std::endl;
	}

	getchar();

	return 0;
}