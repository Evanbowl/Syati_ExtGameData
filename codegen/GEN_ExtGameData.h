#pragma once

#include "syati.h"
#include "ExtGameDataUtil.h"
#include "Game/System/BinaryDataContentAccessor.h"
#include "Game/System/BinaryDataContentHeaderSerializer.h"

{{IncludeList}}
{{ChunkAccessList}}

typedef BinaryDataChunkBase* (*ChunkCreationFunc)();

namespace {
    template<typename T>
    BinaryDataChunkBase* createBinaryChunk() {
        return new T();
    }

    const ChunkCreationFunc cExtSaveChunkCreateTable[] = {
        NULL,
        {{SaveChunkList}}
    };

    const s32 cExtSaveChunkCount = sizeof(cExtSaveChunkCreateTable) / sizeof(ChunkCreationFunc);
}