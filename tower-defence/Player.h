#include <string>

class PlayerClass {

private:

	std::string nickName_;
	std::string playerId_;
	std::string fractionId_;

public:

	PlayerClass() : nickName_("-"), playerId_("-"), fractionId_("-") {}; // default constructor

	PlayerClass(PlayerClass&& player) noexcept {

		this->nickName_ = player.nickName_;
		this->playerId_ = player.playerId_;
		this->fractionId_ = player.fractionId_;

		player.nickName_ = "-";
		player.playerId_ = "-";
		player.fractionId_ = "-";
	}; // move constructor

	PlayerClass(const PlayerClass& copyPlayer) {

		nickName_ = copyPlayer.nickName_;
		playerId_ = copyPlayer.playerId_;
		fractionId_ = copyPlayer.fractionId_;
	};

	void setNickName(std::string nick) {
		this->nickName_ = nick;
	}

	std::string getNickName() {
		return this->nickName_;
	}

	void setPlayerId(std::string id) {
		this->playerId_ = id;
	}

	std::string getPlayerId() {
		return this->playerId_;
	}

	void setFractionId(std::string fractionId) {
		this->fractionId_ = fractionId;
	}

	std::string getFractionId() {
		return this->fractionId_;
	}
};