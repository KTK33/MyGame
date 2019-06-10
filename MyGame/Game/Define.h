#pragma once
//ゲームシステム上のパラメータ

static const float BGMVOLUME = 0.5f;
static const float SEVOLUME = 0.5f;

static int constexpr WINDOW_WIDTH = 1920;
static int constexpr WINDOW_HEIGHT = 1080;

static int constexpr SPACE_DEPTH = 5 - 1;//深度は0〜nの範囲を取る

static int constexpr GRID_X = 10;
static int constexpr GRID_Y = 10;

static constexpr int SEGMENT_VERTEX_COUNT = 2;

///シューティングモード

//プレイヤーの最大ＨＰ
static constexpr int ShootingPlayerHPVal = 10;

//一度にセットできる弾数
static constexpr int SetGunPoint = 7;

//弾を拾ったときに取得できる弾数
static const int GetBulletPoint = 5;

//回復アイテムを拾ったときの回復量
static const int GetHpPoint = 3;

//初期にもっている回復アイテムの数
static const int HaveRecoverItem = 3;

//初期に持っている攻撃アップの数
static const int HaveAttackUpItem = 1;

//敵の落とすアイテムの割合(0〜100) 値が大きいほど弾が落ちやすい、0に近いほど回復アイテムが落ちやすい　100に近いほど弾が落ちやすい
static const int GetItemRate = 70;

//攻撃アップアイテムを使ったときの継続時間(秒)
static const int AttackUpTime = 30;

//ノーマル敵のHP
static const int NormalHPVal = 3;

//ボス敵のHP
static const int BossHPVal = 10;

//大ボスのHP
static const int BigBossHPVal = 10;

///アクションモード

//プレイヤーのHP
static const int ActionPlayerHPVal = 10;

//赤侍のHP
static const int RedSamuraiHPVal = 1;