#pragma once

#include "syati.h"
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
    
    static BinaryDataChunkBase* sExtSaveChunkTable[cExtSaveChunkCount];
}