#include "ExtGameDataUtil.h"
#include "ModuleData_ExtGameData.h"

namespace ExtGameDataUtil {
    BinaryDataChunkBase* getChunk(u32 signature) {
        UserFile *pFile = GameDataFunction::getSaveDataHandleSequence()->getCurrentUserFile();
        return pFile->mGameDataHolder->mBinaryDataChunkHolder->findFromSignature(signature);
    }
}