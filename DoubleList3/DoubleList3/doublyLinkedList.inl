/**
* @file doublyLinkedList.inl
* @brief 双方向リストクラス
* @author 村上輝
* @date 2023/10/17/15:00
* @details 課題1_3「双方向リストのテンプレート化」
*/

#pragma once

#include <assert.h>
#include <string>
#include "doublyLinkedList.h"

//===============================================================
/*双方向リストクラス*/

/**
* @brief 双方向リストクラスのコンストラクタ
* @details データ数、ダミーノードを初期化\n
		   リストが空の場合、ダミーノードの前後はダミーノード自身を参照\n
*/
template<typename DATA>
inline DoublyLinkedList<DATA>::DoublyLinkedList() : m_DataNum(0)
{
	m_DummyNode = new Node();
	m_DummyNode->m_next = m_DummyNode;
	m_DummyNode->m_prev = m_DummyNode;
}

/**
* @brief 双方向リストクラスのデストラクタ
* @details 先頭から末尾までdelete
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
* @brief データ数の取得
* @return リストのデータの総数を返す
*/
template<typename DATA>
inline int DoublyLinkedList<DATA>::GetDataNum() const
{
	return m_DataNum;
}

/**
* @brief データの挿入
* @param[in] it 挿入したい位置のイテレータ
* @param[in] data 挿入したい成績データ
* @return bool(挿入が成功すればtrue、失敗すればfalse)
* @details イテレータの指すノードの前に挿入する
*/
template<typename DATA>
inline bool DoublyLinkedList<DATA>::Insert(ConstIterator & it, const DATA & data)
{
	if (it.m_List != this) return false; // イテレータが別のリストの要素を指すイテレータであったらreturn

	Node* newNode = new Node(data); // 新ノード

	Node* itNode = it.m_Node; // イテレータの指すノード

	// 新ノードの前ノードをイテレータの指す前ノードに。
	newNode->m_prev = itNode->m_prev;

	// 新ノードの次ノードをイテレータの指すノードに。
	newNode->m_next = itNode;

	// イテレータの指すノードの前ノードの次のノードに新ノードを格納
	// (イテレータノードと前ノードの間に格納)
	itNode->m_prev->m_next = newNode;

	// イテレータの指すノードの前ノードに新ノードを格納、これでデータが繋がる
	itNode->m_prev = newNode;

	// データ数を増やす
	m_DataNum++;

	return true;
}

/**
* @brief データの追加
* @param[in] data 追加したい成績データ
* @details 末尾にデータの追加
*/
template<typename DATA>
inline void DoublyLinkedList<DATA>::PushBack(const DATA & data)
{
	DoublyLinkedList<DATA>::ConstIterator endIt = GetCEnd();
	Insert(endIt, data);
}

/**
* @brief データの削除
* @param[in] it 削除したい位置のイテレータ
* @return 削除に失敗したらfalse、成功したらtrueを返す
* @details イテレータの指すノードを削除\n
			データ数が0、イテレータの指すノードがダミーノード、別リストを指すイテレータであれば何も行わない\n
*/
template<typename DATA>
inline bool DoublyLinkedList<DATA>::Remove(ConstIterator & it)
{
	Node* itNode = it.m_Node; // イテレータの指すノード
	if (m_DataNum == 0) return false;
	if (itNode == m_DummyNode) return false;
	if (it.m_List != this) return false; // イテレータが別のリストの要素を指すイテレータであったらreturn


	itNode->m_prev->m_next = itNode->m_next;
	itNode->m_next->m_prev = itNode->m_prev;

	delete itNode;
	m_DataNum--;
	return true;
}

/**
* @brief 先頭イテレータ取得
* @return ダミーノードの次のノード(先頭のイテレータを返す)
*/
template<typename DATA>
inline typename DoublyLinkedList<DATA>::Iterator DoublyLinkedList<DATA>::GetBegin()
{
	return Iterator(m_DummyNode->m_next, this);
}

/**
* @brief 先頭コンストイテレータ取得
* @return ダミーノードの次のノード(先頭のコンストイテレータを返す)
*/
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator DoublyLinkedList<DATA>::GetCBegin() const
{
	return ConstIterator(m_DummyNode->m_next, this);
}

/**
* @brief 末尾イテレータ取得
* @return ダミーノードを返す
*/
template<typename DATA>
inline typename DoublyLinkedList<DATA>::Iterator DoublyLinkedList<DATA>::GetEnd()
{
	return Iterator(m_DummyNode, this);
}

/**
* @brief 末尾コンストイテレータ取得
* @return ダミーノードを返す
*/
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator DoublyLinkedList<DATA>::GetCEnd() const
{
	return ConstIterator(m_DummyNode, this);
}




//===============================================================
/*コンストイテレータ*/

/**
* @brief 引数無しコンストラクタ
*/
template<typename DATA>
inline DoublyLinkedList<DATA>::ConstIterator::ConstIterator() : m_Node(nullptr), m_List(nullptr) {}

/**
* @brief 引数付きコンストラクタ
* @param[in] node イテレータの指す要素
* @param[in] list リストの参照
*/
template<typename DATA>
inline DoublyLinkedList<DATA>::ConstIterator::ConstIterator(Node * node, const DoublyLinkedList* list) : m_Node(node), m_List(list) {}

/**
* @brief コピーコンストラクタ
* @param[in] it コピー元のコンストイテレータ
*/
template<typename DATA>
inline DoublyLinkedList<DATA>::ConstIterator::ConstIterator(const ConstIterator& it) : m_Node(it.m_Node), m_List(it.m_List) {}

/**
* @brief イテレータの先頭に向かってひとつ進める(前置)
* @return 先頭にひとつ進めたイテレータを返す
* @details ノードの参照が無かったらorダミーノードであったらassert
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
* @brief イテレータの先頭に向かってひとつ進める(後置)
* @return 先頭にひとつ進めたイテレータを返す
* @details ノードの参照が無かったらorダミーノードであったらassert
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
* @brief イテレータの末尾に向かってひとつ進める(前置)
* @return 末尾にひとつ進めたイテレータを返す
* @details ノードの参照が無かったらorダミーノードであったらassert
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
* @brief イテレータの末尾に向かってひとつ進める(後置)
* @return 末尾にひとつ進めたイテレータを返す
* @details ノードの参照が無かったらorダミーノードであったらassert
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
* @brief イテレータの指す要素を取得する(const)
* @return イテレータの指す成績データを返す
* @details ノードの参照が無かったらorダミーノードであったらassert
*/
template<typename DATA>
inline const DATA DoublyLinkedList<DATA>::ConstIterator::operator*() const
{
	assert(this->m_Node != nullptr);
	assert(this->m_Node != m_List->m_DummyNode);
	return this->m_Node->m_data;
}

/**
* @brief 代入を行う
* @param[in] it 代入するイテレータ
* @details イテレータのノードを代入する
*/
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator& DoublyLinkedList<DATA>::ConstIterator::operator=(const ConstIterator & it)
{
	m_Node = it.m_Node;
	return *this;
}

/**
* @brief 同一か比較する
* @param[in] it 同一か比較するイテレータ
* @return イテレータの指す要素が同一であればtrueを返す
*/
template<typename DATA>
inline bool DoublyLinkedList<DATA>::ConstIterator::operator==(const ConstIterator & it)
{
	return (m_Node == it.m_Node);
}

/**
* @brief 異なるか比較する
* @param[in] it 異なるか比較するイテレータ
* @return イテレータの指す要素が異なればtrueを返す
*/
template<typename DATA>
inline bool DoublyLinkedList<DATA>::ConstIterator::operator!=(const ConstIterator & it)
{
	return (m_Node != it.m_Node);
}

/**
* @brief イテレータの指すノードがダミーノードか判別する
* @return もしダミーノードであればtrueを返す
* @details テストでダミーノードと比較する際に使用
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
/*イテレータ*/
/**
* @brief 引数無しコンストラクタ
*/
template<typename DATA>
inline DoublyLinkedList<DATA>::Iterator::Iterator() : ConstIterator() {}

/**
* @brief 引数付きコンストラクタ
* @param[in] node イテレータの指す要素
* @param[in] list リストの参照
*/
template<typename DATA>
inline DoublyLinkedList<DATA>::Iterator::Iterator(Node * node, const DoublyLinkedList* list) : ConstIterator(node, list) {}

/**
* @brief イテレータの指す要素を取得する(非const)
* @return イテレータの指す成績データを返す
* @details ノードの参照が無かったらorダミーノードであったらassert
*/
template<typename DATA>
inline DATA & DoublyLinkedList<DATA>::Iterator::operator*()
{
	assert(this->m_Node != nullptr);
	assert(this->m_Node != this->m_List->m_DummyNode);
	return this->m_Node->m_data;
}
