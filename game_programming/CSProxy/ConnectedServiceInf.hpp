//--------------------------------------------------------------------------------------------------
/**
* \~Japanese
* @brief			コネクテッドサービス
* @details			コネクテッドサービスに紐づく情報を取り扱うクラス
*
* \~English			ConnectedService
* @brief
* @details
*
* \~
* @file				connectedservice.hpp
*/
//--------------------------------------------------------------------------------------------------

#ifndef INCLUDE_CONNECTEDSERVICE_HPP_
#define INCLUDE_CONNECTEDSERVICE_HPP_


#include "connectedserviceconnection.hpp"
#include "connectedservicesettingsbuckup.hpp"

namespace aisinlbssdk
{
	/**
	* \~Japanese
	* @brief		コネクテッドサービス
	* @details		コネクテッドサービスに紐づく情報を取り扱うクラス
	* @attention	なし
	*
	* \~English
	* @brief
	* @details
	* @attention
	*/
	class ConnectedService
	{
	public:

		/**
		* \~Japanese
		* @brief		緊急通報状態
		* @attention	なし
		*
		* \~English
		* @brief
		* @attention
		*/
		enum class EmergencyCallStatus : uint32_t
		{
			//! \~Japanese Off
			//! \~English
			Off,
			//! \~Japanese On
			//! \~English
			On
		};

		/**
		* \~Japanese
		* @brief		通話状態
		* @attention	なし
		*
		* \~English
		* @brief
		* @attention
		*/
		enum class CallState : uint32_t
		{
			//! \~Japanese 情報なし
			//! \~English
			None,
			//! \~Japanese 発信中
			//! \~English
			Calling,
			//! \~Japanese 通話中
			//! \~English
			Voice,
			//! \~Japanese 通話不能
			//! \~English
			Impossible
		};
		
		/**
		* \~Japanese
		* @brief		コネクテッド通知種別
		* @attention	なし
		*
		* \~English
		* @brief
		* @attention
		*/
		enum class ConnectedInformationKind : uint32_t
		{
			//! \~Japanese リコール通知
			//! \~English
			Recall,
			//! \~Japanese 新着のお知らせ
			//! \~English
			Inspection,
			//! \~Japanese 定期点検
			//! \~English
			PeriodicInspection,
			//! \~Japanese 車検
			//! \~English
			VehicleInspection,
			//! \~Japanese 故障通知
			//! \~English
			Failure
		};

		/**
		* \~Japanese
		* @brief		再通知フラグ
		* @attention	なし
		*
		* \~English
		* @brief
		* @attention
		*/
		enum class ReNotificationFlag : uint32_t
		{
			//! \~Japanese 必要
			//! \~English
			Necessary,

			//! \~Japanese 不必要
			//! \~English
			UnNecessary
		};

		//! \~Japanese	コネクテッド通知情報
		//! \~English
		struct ConnectedInformation
		{
			//! \~Japanese コネクテッド通知種別
			//! \~English
			ConnectedInformationKind		kind;

			//! \~Japanese 年
			//! \~English
			uint32_t						year;

			//! \~Japanese 月
			//! \~English
			uint32_t						month;

			//! \~Japanese 日
			//! \~English
			uint32_t						day;

			//! \~Japanese 再通知フラグ
			//! \~English
			ReNotificationFlag				reminder;
		};

		/**
		* \~Japanese
		* @brief		テレマ契約フラグ
		* @attention	なし
		*
		* \~English
		* @brief
		* @attention
		*/
		enum class TelemarketingContractFlag : uint32_t
		{
			//! \~Japanese Off
			//! \~English
			Off,

			//! \~Japanese On
			//! \~English
			On
		};

		/**
		* \~Japanese
		* @brief		コネクテッド設定フラグ
		* @attention	なし
		*
		* \~English
		* @brief
		* @attention
		*/
		enum class ConnectedSetupFlag : uint32_t
		{
			//! \~Japanese Off
			//! \~English
			Off,

			//! \~Japanese On
			//! \~English
			On
		};

		/**
		* \~Japanese
		* @brief		修理中設定フラグ
		* @attention	なし
		*
		* \~English
		* @brief
		* @attention
		*/
		enum class RepairedSetupFlag : uint32_t
		{
			//! \~Japanese Off
			//! \~English
			Off,

			//! \~Japanese On
			//! \~English
			On
		};

		/**
		* \~Japanese
		* @brief		壁紙ダウンロード結果
		* @attention	なし
		*
		* \~English
		* @brief
		* @attention
		*/
		enum class WallPeperDownLoadResult : uint32_t
		{
			//! \~Japanese データ無し
			//! \~English
			NoData,
			//! \~Japanese ダウンロード中
			//! \~English
			Loading,
			//! \~Japanese ダウンロード完了
			//! \~English
			Completion,
			//! \~Japanese ダウンロード失敗
			//! \~English
			Failure,
			//! \~Japanese 未保存有り
			//! \~English
			UnSaveExisted
		};

		/**
		* \~Japanese
		* @brief		保存状態
		* @attention	なし
		*
		* \~English
		* @brief
		* @attention
		*/
		enum class SaveStatus : uint32_t
		{
			//! \~Japanese 未保存
			//! \~English
			UnSave,
			//! \~Japanese 保存済み
			//! \~English
			Saved
		};

		/**
		* \~Japanese
		* @brief		画像データ(base64)
		* @attention	空き領域の判断は「dayData.size()」、または「nightData.size()」で実施すること。
		*
		* \~English
		* @brief
		* @attention
		*/
		struct ImageDataBase64
		{
			//! \~Japanese 画像データ(昼)
			//! \~English
			std::string		dayData;

			//! \~Japanese 画像データ(夜)
			//! \~English
			std::string		nightData;

			//! \~Japanese トリミング表示開始位置情報(X軸)
			//! \~English
			uint32_t		trimmingX;

			//! \~Japanese トリミング表示開始位置情報(Y軸)
			//! \~English
			uint32_t		trimmingY;
		};

		/**
		* \~Japanese
		* @brief		音声制御イベント
		* @attention	なし
		*
		* \~English
		* @brief
		* @attention
		*/
		enum class AudioControlEvent : uint32_t
		{
			//! \~Japanese 緊急通報開始
			//! \~English
			EmergencyCallStart,
			//! \~Japanese 緊急通報終了
			//! \~English
			EmergencyCallEnd,
			//! \~Japanese コールセンター連絡（スズキトラブルサポート）開始
			//! \~English
			CallcenterContactStart,
			//! \~Japanese コールセンター連絡（スズキトラブルサポート）終了
			//! \~English
			CallcenterContactEnd
		};

		/**
		* \~Japanese
		* @brief		デジタルキー適用状態
		* @attention	なし
		*/
		enum class DigitalKeyActiveStatus : uint32_t
		{
			//! \~Japanese 非適用
			NoActive,

			//! \~Japanese 適用
			Active
		};

		/**
		* \~Japanese
		* @brief		デジタルキー設定状態
		* @attention	なし
		*/
		enum class DigitalKeySettingStatus : uint32_t
		{
			//! \~Japanese Off
			Off,

			//! \~Japanese On
			On
		};

		/**
		* \~Japanese
		* @brief		デジタルキー応答結果
		* @attention	なし
		*/
		enum class DigitalKeyResponseResult : uint32_t
		{
			//! \~Japanese 正常終了
			Ok,

			//! \~Japanese 削除中
			Deleting,

			//! \~Japanese エラー：Fobキー,オーナーキーが存在しない
			FobKeyOwnerKeyNotFound,

			//! \~Japanese エラー：Fobキーが存在しない
			FobKeyNotFound,

			//! \~Japanese エラー：アップデート失敗
			UpdateFail,

			//! \~Japanese エラー：テレマティクスの範囲外
			TelematicsOufOfRange,

			//! \~Japanese エラー：テレマティクスのアップロード失敗
			TelematicsUpdateFail,

			//! \~Japanese エラー：サーバーから応答無し
			SeverErrorResponse,

			//! \~Japanese エラー：デジタルキー無し
			NoDigitalKey,

			//! \~Japanese エラー：キュー溢れ
			QueueFull
		};

		/**
		* \~Japanese
		* @brief		DCM電波状態
		* @attention	なし
		*/
		enum class DcmWaveStatus : uint32_t
		{
			//! \~Japanese 電波強度レベル0
			Level0,

			//! \~Japanese 電波強度レベル1
			Level1,

			//! \~Japanese 電波強度レベル2
			Level2,

			//! \~Japanese 電波強度レベル3
			Level3,

			//! \~Japanese 電波強度レベル4
			Level4,

			//! \~Japanese 電波強度レベル5
			Level5,

			//! \~Japanese 圏外
			OutOfRange
		};

		/**
		* \~Japanese
		* @brief		コネクテッド通知
		* @details		コネクテッド通知
		* @attention	なし
		*
		* \~English
		* @brief
		* @details
		* @attention
		*/
		typedef std::function<void( )> OnConnectedInformation;

		/**
		* \~Japanese
		* @brief		ネットワークリセット結果
		* @attention	なし
		*
		* \~English
		* @brief
		* @attention
		*/
		enum class NetworkConnectionResetResult : uint32_t
		{
			//! \~Japanese 失敗
			//! \~English
			Failure,
			//! \~Japanese リセット処理中
			//! \~English
			Resetting,
			//! \~Japanese 成功
			//! \~English
			Success
		};

		/**
		* \~Japanese
		* @brief		ネットワークリセット結果通知コールバック
		* @details		ネットワークリセット結果通知コールバック
		* @attention	なし
		*
		* \~English
		* @brief
		* @details
		* @attention
		*/
		typedef std::function<void( aisinlbssdk::ConnectedService::NetworkConnectionResetResult result )> OnNetworkConnectionResetResult;

		/**
		* \~Japanese
		* @brief		緊急通報コールバック
		* @details		緊急通報コールバック
		* @attention	なし
		*
		* \~English
		* @brief
		* @details
		* @attention
		*/
		typedef std::function<void( aisinlbssdk::ConnectedService::EmergencyCallStatus state )> OnEmergencyReporting;

		/**
		* \~Japanese
		* @brief		状態変化通知コールバック
		* @details		状態変化通知コールバック
		* @attention	なし
		*
		* \~English
		* @brief
		* @details
		* @attention
		*/
		typedef std::function<void( )> OnConnectedChanged;

		/**
		* \~Japanese
		* @brief		壁紙ダウンロード結果通知コールバック
		* @details		壁紙ダウンロード結果通知コールバック
		* @attention	なし
		*
		* \~English
		* @brief
		* @details
		* @attention
		*/
		typedef std::function<void( aisinlbssdk::ConnectedService::WallPeperDownLoadResult result )> OnWallPaperDownLoad;

		/**
		* \~Japanese
		* @brief		壁紙取得応答コールバック
		* @details		壁紙取得応答コールバック
		* @attention	なし
		*
		* \~English
		* @brief
		* @details
		* @attention
		*/
		typedef std::function<void( std::vector<ImageDataBase64>& dataList )> OnGetWallPaperResponse;


		/**
		* \~Japanese
		* @brief		音声制御イベント受信処理
		* @details		音声制御イベント受信処理
		* @attention	なし
		*
		* \~English
		* @brief
		* @details
		* @attention
		*/
		typedef std::function<void( aisinlbssdk::ConnectedService::AudioControlEvent ctrlEvent)> OnAudioControl;

		/**
		* \~Japanese
		* @brief		デジタルキー適用情報通知コールバック
		* @details		デジタルキー適用情報通知コールバック
		* @attention	なし
		*/
		typedef std::function<void( aisinlbssdk::optional<DigitalKeyActiveStatus> status )> OnDigitalKeyActiveStatus;

		/**
		* \~Japanese
		* @brief		デジタルキー設定状態通知コールバック
		* @details		デジタルキー設定状態通知コールバック
		* @attention	なし
		*/
		typedef std::function<void( aisinlbssdk::optional<DigitalKeySettingStatus> status )> OnDigitalKeySettingStatus;

		/**
		* \~Japanese
		* @brief		デジタルキー設定切り替え結果通知コールバック
		* @details		デジタルキー設定切り替え結果通知コールバック
		* @attention	なし
		*/
		typedef std::function<void( aisinlbssdk::ConnectedService::DigitalKeyResponseResult result)> OnDigitalKeySettingChangeResult;

		/**
		* \~Japanese
		* @brief		デジタルキー削除結果通知コールバック
		* @details		デジタルキー削除結果通知コールバック
		* @attention	なし
		*/
		typedef std::function<void( aisinlbssdk::ConnectedService::DigitalKeyResponseResult result)> OnDigitalKeyDeleteResult;

		/**
		* \~Japanese
		* @brief		DCM電波状態変化通知コールバック
		* @details		DCM電波状態変化通知コールバック
		* @attention	なし
		*/
		typedef std::function<void( aisinlbssdk::optional<DcmWaveStatus> status )> OnDcmWaveStatusChanged;

	private:
		//! \~Japanese テレマ契約フラグ
		//! \~English
		aisinlbssdk::optional<TelemarketingContractFlag> telematicsServiceState_;

		//! \~Japanese テレマ契約フラグ初回バックアップ通知確認フラグ
		//! \~English
		bool initial_TelemarketingStateCheckFlag_;

		//! \~Japanese 緊急通報状態
		//! \~English
		aisinlbssdk::optional<EmergencyCallStatus> emergencyReportingState_;

		//! \~Japanese 通話状態
		//! \~English
		aisinlbssdk::optional<CallState> callState_;

		//! \~Japanese コネクテッド設定フラグ
		//! \~English
		aisinlbssdk::optional<ConnectedSetupFlag> connectedServiceSettingState_;

		//! \~Japanese 修理中設定フラグ
		//! \~English
		aisinlbssdk::optional<RepairedSetupFlag> connectedServiceRepairState_;

		//! \~Japanese 緊急通報コールバック(ConnectedService⇔Connection用)
		//! \~English
		aisinlbssdk::OnEmergencyReportingConnection onEmergencyReportingConnectionCallback_;

		//! \~Japanese コネクテッド通知コールバック(ConnectedService⇔Connection用)
		//! \~English
		aisinlbssdk::OnConnectedInformationConnection onConnectedInformationConnectionCallback_;

		//! \~Japanese ネットワークリセット結果通知コールバック(ConnectedService⇔Connection用)
		//! \~English
		aisinlbssdk::OnNetworkConnectionResetResultConnection onNetworkConnectionResetResultConnectionCallback_;

		//! \~Japanese 状態変化通知コールバック(ConnectedService⇔Connection用)
		//! \~English
		aisinlbssdk::OnConnectedChangedConnection onConnectedChangedConnectionCallback_;

		//! \~Japanese 壁紙ダウンロード通知(コネクテッド通知)コールバック(ConnectedService⇔Connection用)
		//! \~English
		aisinlbssdk::OnWallPaperDownLoadConnection onWallPaperDownLoadConnectionCallback_;

		//! \~Japanese 画像データ、トリミング情報通知(コネクテッド通知)コールバック(ConnectedService⇔Connection用)
		//! \~English
		aisinlbssdk::OnImageDataDownLoadConnection onImageDataDownLoadConnectionCallback_;

		//! \~Japanese デジタルキー情報通知コールバックの設定(ConnectedService⇔Connection)
		aisinlbssdk::OnDigitalKeyConnection onDigitalKeyConnectionCallback_;

		//! \~Japanese バックアップ通知(テレマ契約フラグ)コールバック(ConnectedService⇔Buckup用)
		//! \~English
		aisinlbssdk::OnTelemarketingContractFlagBuckup onTelemarketingContractFlagBuckupCallback_;

		//! \~Japanese バックアップ通知(コネクテッド通知)コールバック(ConnectedService⇔Buckup用)
		//! \~English
		aisinlbssdk::OnConnectedInformationBuckup onConnectedInformationBuckupCallback_;

		//! \~Japanese 緊急通報コールバックメソッドリスト
		//! \~English
		std::vector<OnEmergencyReporting*> emergencyReportingCallbacklist_;

		//! \~Japanese コネクテッド通知コールバックメソッドリスト
		//! \~English
		std::vector<OnConnectedInformation*> connectedInformationCallbacklist_;

		//! \~Japanese ネットワークリセット結果通知コールバックメソッドリスト
		//! \~English
		std::vector<OnNetworkConnectionResetResult*> networkConnectionResetCallbacklist_;

		//! \~Japanese 状態変化通知コールバックメソッドリスト
		//! \~English
		std::vector<OnConnectedChanged*> connectedChangedCallbacklist_;

		//! \~Japanese 壁紙取得応答コールバックメソッドリスト
		//! \~English
		std::vector<OnWallPaperDownLoad*> wallPaperDownLoadCallbacklist_;
		
		//! \~Japanese 壁紙データリストコールバックメソッドリスト
		//! \~English
		std::vector<OnGetWallPaperResponse*> wallPaperResponseCallbacklist_;

		//! \~Japanese デジタルキー適用情報通知コールバックリスト
		std::vector<const OnDigitalKeyActiveStatus*> digitalKeyActiveStatusCallbackList_;

		//! \~Japanese デジタルキー設定状態通知コールバックリスト
		std::vector<const OnDigitalKeySettingStatus*> digitalKeySettingStatusCallbackList_;

		//! \~Japanese デジタルキー設定切り替え結果通知コールバックリスト
		std::vector<const OnDigitalKeySettingChangeResult*> digitalKeySettingChangeResultCallbackList_;

		//! \~Japanese デジタルキー削除結果通知コールバックリスト
		std::vector<const OnDigitalKeyDeleteResult*> digitalKeyDeleteResultCallbackList_;

		//! \~Japanese DCM電波状態変化通知コールバックリスト
		std::vector<const OnDcmWaveStatusChanged*> dcmWaveStatusChangedCallbackList_;

		//! \~Japanese ConnectedServiceSettingsConnectionクラスのインスタンス
		//! \~English
		aisinlbssdk::ConnectedServiceSettingsConnection connectedServiceSettingsConnection_;

		//! \~Japanese ConnectedServiceSettingsBuckupクラスのインスタンス
		//! \~English
		aisinlbssdk::ConnectedServiceSettingsBuckup connectedServiceSettingsBuckup_;

		//! \~Japanese 画像データ一時保存
		//! \~English
		std::string recvImagedata_;

		//! \~Japanese トリミング情報X一時保存
		//! \~English
		int32_t recvTrimmingX_;

		//! \~Japanese トリミング情報Y一時保存
		//! \~English
		int32_t recvTrimmingY_;

		//! \~Japanese デジタルキー適用情報
		aisinlbssdk::optional<DigitalKeyActiveStatus> digitalKeyActiveStatus_;

		//! \~Japanese デジタルキー設定状態
		aisinlbssdk::optional<DigitalKeySettingStatus> digitalKeySettingStatus_;

		//! \~Japanese DCM電波状態
		aisinlbssdk::optional<aisinlbssdk::ConnectedService::DcmWaveStatus> dcmWaveStatus_;

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		緊急通報コールバック(ConnectedService⇔Connection用)の設定
		*
		* \~English
		* @brief		
		*/
		//---------------------------------------------------------------------------
		void setOnEmergencyReportingConnection();

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		コネクテッド通知コールバック(ConnectedService⇔Connection用)の設定
		*
		* \~English
		* @brief		
		*/
		//---------------------------------------------------------------------------
		void setOnConnectedInformationConnection();

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		ネットワークリセット結果通知コールバック(ConnectedService⇔Connection用)の設定
		*
		* \~English
		* @brief		
		*/
		//---------------------------------------------------------------------------
		void setOnNetworkConnectionResetResultConnection();

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		状態変化通知コールバック(ConnectedService⇔Connection用)の設定
		*
		* \~English
		* @brief		
		*/
		//---------------------------------------------------------------------------
		void setOnConnectedChangedConnection();

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		壁紙ダウンロード通知コールバック(ConnectedService⇔Connection用)の設定
		*
		* \~English
		* @brief		
		*/
		//---------------------------------------------------------------------------
		void setOnWallPaperDownLoadConnection();
		
		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		画像データ、トリミング情報通知コールバック(ConnectedService⇔Connection用)の設定
		*
		* \~English
		* @brief		
		*/
		//---------------------------------------------------------------------------
		void setOnImageDataDownLoadConnection();

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		デジタルキー情報通知コールバックの設定(ConnectedService⇔Connection)
		*/
		//---------------------------------------------------------------------------
		void setOnDigitalKeyConnection();

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		バックアップ通知コールバック(ConnectedService⇔Buckup用)の設定
		*
		* \~English
		* @brief		
		*/
		//---------------------------------------------------------------------------
		void setOnConnectedServiceBuckup();
		
		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		テレマ契約フラグを更新
		* @param[in]	recvData	設定値
		*
		* \~English
		* @brief
		* @param[in]
		*/
		//---------------------------------------------------------------------------
		void updateTelematicsServiceState( uint32_t recvData, uint32_t recvFlag );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		壁紙ダウンロード要求応答スレッド
		* @param[in]	saveStatus	保存種別
		* @param[in]	callback	コールバックアドレス
		*
		* \~English
		* @brief
		* @param[in]
		*/
		//---------------------------------------------------------------------------
		void threadreqestWallPaper( );
	
		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		bese64フォーマット
		* @param[in]	strBytes	変換前バイナリーデータ
		* @param[in]	sendstrBytes	変換後バイナリーデータ
		*
		* \~English
		* @brief
		* @param[in]
		*/
		//---------------------------------------------------------------------------
		void encodeToBase64(std::string& instrBytes, std::string& outstrbase64);

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		デジタルキー適用情報のプロパティ更新, コールバック通知
		*/
		//---------------------------------------------------------------------------
		void updateDigitalKeyActiveStatus( const uint32_t recvData );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		デジタルキー設定状態のプロパティ更新, コールバック通知
		*/
		//---------------------------------------------------------------------------
		void updateDigitalKeySettingStatus( const uint32_t recvData );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		デジタルキー設定切り替え結果コールバック通知
		*/
		//---------------------------------------------------------------------------
		void responseDigitalKeySettingChangeResult( const uint32_t recvData );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		デジタルキー削除結果通知コールバック
		*/
		//---------------------------------------------------------------------------
		void responseDigitalKeyDeleteResult( const uint32_t recvData );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		DCM電波状態：プロパティ更新
		*/
		//---------------------------------------------------------------------------
		bool updateDcmWaveStatus( const uint32_t recvData );

	public:
		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		コンストラクタ
		*
		* \~English
		* @brief		Constructor
		*/
		//---------------------------------------------------------------------------
		ConnectedService();

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		デストラクタ
		*
		* \~English
		* @brief		Destructor
		*/
		//---------------------------------------------------------------------------
		~ConnectedService();

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		緊急通報コールバックの登録
		* @param[in]	onEmergencyReporting	コールバックメソッドアドレス
		*
		* \~English
		* @brief
		* @param[in]
		*/
		//---------------------------------------------------------------------------
		void addOnEmergencyReporting( OnEmergencyReporting& onEmergencyReporting );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		緊急通報状態を取得
		* @retval		緊急通報状態
		* @attention	戻り値が「aisinlbssdk::nullopt」、または「has_value()の結果がfalse」の場合、緊急通報による操作制限は行わないこと
		*
		* \~English
		* @brief
		* @retval
		*/
		//---------------------------------------------------------------------------
		aisinlbssdk::optional<EmergencyCallStatus> getEmergencyReportingState();

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		緊急通報コールバックの破棄
		* @param[in]	onEmergencyReporting	コールバックメソッドアドレス
		*
		* \~English
		* @brief
		* @param[in]
		*/
		//---------------------------------------------------------------------------
		void removeOnEmergencyReporting( OnEmergencyReporting& onEmergencyReporting );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		通話要求
		* @retval		true	要求成功
		* @retval		false	要求失敗
		*
		* \~English
		* @brief
		* @retval
		*/
		//---------------------------------------------------------------------------
		bool requestStartCall();

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		終話要求
		* @retval		true	要求成功
		* @retval		false	要求失敗
		*
		* \~English
		* @brief
		* @retval
		*/
		//---------------------------------------------------------------------------
		bool requestEndCall();

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		通話状態を取得
		* @retval		通話状態
		* @attention	戻り値が「aisinlbssdk::nullopt」、または「has_value()の結果がfalse」の場合、項目「スズキトラブルサポートへ連絡する」は非表示とすること
		*
		* \~English
		* @brief
		* @retval
		*/
		//---------------------------------------------------------------------------
		aisinlbssdk::optional<CallState> getCallState();

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		コネクテッド通知コールバックの登録
		* @param[in]	onConnectedInformation	コールバックメソッドアドレス
		*
		* \~English
		* @brief
		* @param[in]
		*/
		//---------------------------------------------------------------------------
		void addOnConnectedInformation( OnConnectedInformation& onConnectedInformation );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		コネクテッド通知履歴を取得
		* @retval		コネクテッド通知履歴
		* @attention	戻り値が「aisinlbssdk::nullopt」、または「has_value()の結果がfalse」の場合、項目「通知履歴」は非表示とすること
		*
		* \~English
		* @brief
		* @retval
		*/
		//---------------------------------------------------------------------------
		std::vector<aisinlbssdk::ConnectedService::ConnectedInformation> getConnectedInformation();

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		コネクテッド通知の再通知を不要に設定
		* @param[in]	information		再通知不要に設定したコネクテッド通知情報
		* @attention	ユーザー操作による消去、もしくは表示してから8秒経過後に本メソッドをコールすること
		*
		* \~English
		* @brief
		* @param[in]
		* @retval
		*/
		//---------------------------------------------------------------------------
		void setConnectedInformationReminderOff( aisinlbssdk::ConnectedService::ConnectedInformation information );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		コネクテッド通知履歴の削除要求
		* @param[in]	index	コネクテッド通知履歴の要素番号
		* @retval		true	要求成功
		* @retval		false	要求失敗
		*
		* \~English
		* @brief
		* @param[in]
		* @retval
		*/
		//---------------------------------------------------------------------------
		bool deleteConnectedInformation( std::vector<uint32_t> index );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		コネクテッド通知コールバックの破棄
		* @param[in]	onConnectedInformation	コールバックメソッドアドレス
		*
		* \~English
		* @brief
		* @param[in]
		*/
		//---------------------------------------------------------------------------
		void removeOnConnectedInformation( OnConnectedInformation& onConnectedInformation );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		テレマ契約フラグを取得
		* @retval		テレマ契約フラグ
		* @attention	戻り値が「aisinlbssdk::nullopt」、または「has_value()の結果がfalse」の場合、項目「コネクテッドサービス設定」は非表示とすること
		*
		* \~English
		* @brief
		* @retval
		*/
		//---------------------------------------------------------------------------
		aisinlbssdk::optional<TelemarketingContractFlag> getTelematicsServiceState();

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		コネクテッド設定フラグを取得
		* @retval		コネクテッド設定フラグ
		* @attention	戻り値が「aisinlbssdk::nullopt」、または「has_value()の結果がfalse」の場合、項目「コネクテッドサービス設定」は非表示とすること
		*
		* \~English
		* @brief
		* @retval
		*/
		//---------------------------------------------------------------------------
		aisinlbssdk::optional<ConnectedSetupFlag> getConnectedServiceSettingState();

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		コネクテッド設定フラグの設定
		* @param[in]	connectedServiceSettingState	コネクテッド設定フラグ
		* @retval		true	要求成功
		* @retval		false	要求失敗
		*
		* \~English
		* @brief
		* @param[in]
		* @retval
		*/
		//---------------------------------------------------------------------------
		bool setConnectedServiceSettingState( ConnectedSetupFlag connectedServiceSettingState );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		修理中設定フラグを取得
		* @retval		修理中設定フラグ
		* @attention	戻り値が「aisinlbssdk::nullopt」、または「has_value()の結果がfalse」の場合、項目「コネクテッド設定フラグ(修理中モード)」は非表示とすること
		*
		* \~English
		* @brief
		* @retval
		*/
		//---------------------------------------------------------------------------
		aisinlbssdk::optional<RepairedSetupFlag> getConnectedServiceRepairState();

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		修理中設定フラグの設定
		* @param[in]	connectedServiceRepairState	修理中設定フラグ
		* @retval		true	要求成功
		* @retval		false	要求失敗
		*
		* \~English
		* @brief
		* @param[in]
		* @retval
		*/
		//---------------------------------------------------------------------------
		bool setConnectedServiceRepairState( RepairedSetupFlag connectedServiceRepairState );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		ネットワークリセット結果通知コールバックの登録
		* @param[in]	onNetworkConnectionResetResult	コールバックメソッドアドレス
		*
		* \~English
		* @brief
		* @param[in]
		*/
		//---------------------------------------------------------------------------
		void addOnNetworkConnectionResetResult( OnNetworkConnectionResetResult& onNetworkConnectionResetResult );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		ネットワークリセット要求
		* @retval		true	要求成功
		* @retval		false	要求失敗
		*
		* \~English
		* @brief
		* @retval
		* @retval
		*/
		//---------------------------------------------------------------------------
		bool requestNetworkConnectionReset();

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		ネットワークリセット結果通知コールバックの破棄
		* @param[in]	onNetworkConnectionResetResult	コールバックメソッドアドレス
		*
		* \~English
		* @brief
		* @param[in]
		*/
		//---------------------------------------------------------------------------
		void removeOnNetworkConnectionResetResult( OnNetworkConnectionResetResult& onNetworkConnectionResetResult );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		状態変化通知コールバックの登録
		* @param[in]	onConnectedChanged	コールバックメソッドアドレス
		*
		* \~English
		* @brief
		* @param[in]
		*/
		//---------------------------------------------------------------------------
		void addOnConnectedChanged( OnConnectedChanged& onConnectedChanged );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		状態変化通知コールバックの破棄
		* @param[in]	onConnectedChanged	コールバックメソッドアドレス
		*
		* \~English
		* @brief
		* @param[in]
		*/
		//---------------------------------------------------------------------------
		void removeOnConnectedChanged( OnConnectedChanged& onConnectedChanged );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		壁紙ダウンロード結果通知コールバックの登録
		* @param[in]	callback	コールバックメソッドアドレス
		*
		* \~English
		* @brief
		* @param[in]
		*/
		//---------------------------------------------------------------------------
		void addOnWallPaperDownLoad( OnWallPaperDownLoad& callback );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		壁紙ダウンロード結果通知コールバックの破棄
		* @param[in]	callback	コールバックメソッドアドレス
		*
		* \~English
		* @brief
		* @param[in]
		*/
		//---------------------------------------------------------------------------
		void removeOnWallPaperDownLoad( OnWallPaperDownLoad& callback );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		壁紙データの取得
		* @retval		true	要求成功
		* @retval		false	要求失敗
		* @details 		保存済みの壁紙データ、もしくは未保存の壁紙データを取得
		* @param[in]	status		保存状態
		* @param[in]	callback	壁紙取得応答のコールバックメソッドアドレス
		* @attention	
		* 第一引数に「保存済み」指定：保存済みの画像データを返却。<br>
		* 第一引数に「未保存」指定、かつ第二引数のsizeが「0」：未保存の画像データを返却。<br>
		*
		* \~English
		* @brief
		* @retval
		*/
		//---------------------------------------------------------------------------
		bool getWallPaperData( SaveStatus status, OnGetWallPaperResponse& callback );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		壁紙ダウンロード要求
		* @retval		true	要求成功
		* @retval		false	要求失敗
		*
		* \~English
		* @brief
		* @retval
		* @retval
		*/
		//---------------------------------------------------------------------------
		bool reqestWallPaperDownLoad();

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		壁紙保存要求
		* @param[in]	index	壁紙の保存位置（0スタート）
		* @retval		true	要求成功
		* @retval		false	要求失敗
		*
		* \~English
		* @brief
		* @retval
		* @retval
		*/
		//---------------------------------------------------------------------------
		bool reqestWallPaperDataSeve( uint8_t index );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		壁紙削除要求
		* @param[in]	index	削除する壁紙の位置（0スタート）
		* @retval		true	要求成功
		* @retval		false	要求失敗
		*
		* \~English
		* @brief
		* @retval
		* @retval
		*/
		//---------------------------------------------------------------------------
		bool reqestRemoveWallPeper( std::vector<uint8_t> index );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		音声制御イベント通知先登録
		* @param[in]	callback	音声制御イベント受信処理
		* @retval		true	登録成功
		* @retval		false	登録失敗
		*
		* \~English		Register callback for audio control events
		* @brief
		* @retval
		* @retval
		*/
		//---------------------------------------------------------------------------
		bool addOnAudioController( const aisinlbssdk::ConnectedService::OnAudioControl callback );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		デジタルキー適用情報通知コールバック登録
		* @param[in]	callback	コールバックメソッドアドレス
		*/
		//---------------------------------------------------------------------------
		void addOnDigitalKeyActiveStatus( const OnDigitalKeyActiveStatus& callback );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		デジタルキー適用情報通知コールバック破棄
		* @param[in]	callback	コールバックメソッドアドレス
		*/
		//---------------------------------------------------------------------------
		void removeOnDigitalKeyActiveStatus( const OnDigitalKeyActiveStatus& callback );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		デジタルキー適用情報の取得
		* @retval		デジタルキー適用情報
		*/
		//---------------------------------------------------------------------------
		aisinlbssdk::optional<DigitalKeyActiveStatus> getDigitalKeyActiveStatus();

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		デジタルキー設定状態通知コールバック登録
		* @param[in]	callback	コールバックメソッドアドレス
		*/
		//---------------------------------------------------------------------------
		void addOnDigitalKeySettingStatus( const OnDigitalKeySettingStatus& callback );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		デジタルキー設定状態通知コールバック破棄
		* @param[in]	callback	コールバックメソッドアドレス
		*/
		//---------------------------------------------------------------------------
		void removeOnDigitalKeySettingStatus( const OnDigitalKeySettingStatus& callback );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		デジタルキー設定状態の取得
		* @retval		デジタルキー設定状態
		*/
		//---------------------------------------------------------------------------
		aisinlbssdk::optional<DigitalKeySettingStatus> getDigitalKeySettingStatus();

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		デジタルキー設定切り替え結果通知コールバック登録
		* @param[in]	callback	コールバックメソッドアドレス
		*/
		//---------------------------------------------------------------------------
		void addOnDigitalKeySettingChangeResult( const OnDigitalKeySettingChangeResult& callback );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		デジタルキー設定切り替え結果通知コールバック破棄
		* @param[in]	callback	コールバックメソッドアドレス
		*/
		//---------------------------------------------------------------------------
		void removeOnDigitalKeySettingChangeResult( const OnDigitalKeySettingChangeResult& callback );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		デジタルキー設定状態の設定要求
		* @param[in]	status	デジタルキー設定状態
		* @retval		true	要求成功
		* @retval		false	要求失敗
		*/
		//---------------------------------------------------------------------------
		bool setDigitalKeySettingStatus( const DigitalKeySettingStatus status );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		デジタルキー削除結果通知コールバック登録
		* @param[in]	callback	コールバックメソッドアドレス
		*/
		//---------------------------------------------------------------------------
		void addOnDigitalKeyDeleteResult( const OnDigitalKeyDeleteResult& callback );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		デジタルキー削除結果通知コールバック破棄
		* @param[in]	callback	コールバックメソッドアドレス
		*/
		//---------------------------------------------------------------------------
		void removeOnDigitalKeyDeleteResult( const OnDigitalKeyDeleteResult& callback );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		デジタルキーの削除要求
		* @retval		true	要求成功
		* @retval		false	要求失敗
		*/
		//---------------------------------------------------------------------------
		bool deleteDigitalKey();

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		DCM電波状態変化通知コールバック登録
		* @param[in]	callback	コールバックメソッドアドレス
		*/
		//---------------------------------------------------------------------------
		void addOnDcmWaveStatusChanged( const OnDcmWaveStatusChanged& callback );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		DCM電波状態変化通知コールバック破棄
		* @param[in]	callback	コールバックメソッドアドレス
		*/
		//---------------------------------------------------------------------------
		void removeOnDcmWaveStatusChanged( const OnDcmWaveStatusChanged& callback );

		//---------------------------------------------------------------------------
		/**
		* \~Japanese
		* @brief		DCM電波状態の取得
		* @retval		DCM電波状態
		*/
		//---------------------------------------------------------------------------
		aisinlbssdk::optional<DcmWaveStatus> getDcmWaveStatus();
	};
};

#endif /* INCLUDE_CONNECTEDSERVICE_HPP_ */