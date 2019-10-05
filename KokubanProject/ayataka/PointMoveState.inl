#include "PointMoveState.h"

namespace Eraser
{
	PointMoveState::PointMoveState()
	{

	}

	PointMoveState::~PointMoveState()
	{

	}

	void PointMoveState::Update()
	{
		// エリアの重み算出


		// 目標座標の算出
		Move();
		
		// 目標座標の送信

	}

	void PointMoveState::Move()
	{
		// 自身から最も近い点を取得する
		m_targetPos = FindNearest(m_nowArea);
	}

	inline cv::Point2i PointMoveState::FindNearest(int index)
	{
		cv::Point2i target;
		float minDist = 100000.0f;
		float dist = 0.0f;

		for (auto chalk : chalkPoints)
		{
			dist = cv::norm(chalk - nowPoint);
			if (minDist > dist)
			{
				target = chalk;
				minDist = dist;
			}
		}

		return target;
	}
}