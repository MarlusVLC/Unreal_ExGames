// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "ExGamesCharacterBase.h"
#include "ExGamesLib.generated.h"

/**
 *
 */
UENUM(BluePrintType, Category = "ExGame|Enums")
enum class ExGame_EstadoCubo : uint8 {
    ExGame_Idle     UMETA(DisplayName = "Cubo Idle"),
    ExGame_Moving   UMETA(DisplayName = "Cubo Moving"),
    ExGame_Colision UMETA(DisplayName = "Cubo Colision"),
};

UENUM(BluePrintType, Category = "ExGame|Enums")
enum class ExGame_EstadoJogo : uint8 {
    ExGame_Init      UMETA(DisplayName = "Jogo Inicializado"),
    ExGame_Run       UMETA(DisplayName = "Jogo Rodando"),
    ExGame_Stage     UMETA(DisplayName = "Mudar de Fase"),
};

/**
 *Armazena dados gerais do jogo através de uma estrutura global
 */
USTRUCT(BlueprintType, Category = "ExGame|Structs")
struct FExGames_DadosJogo {
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TSoftClassPtr<UObject> pExGameCubo01;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TSoftClassPtr<UObject> pExGameCubo02;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TSoftClassPtr<UObject> pExGameCubo03;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TSoftClassPtr<UObject> pExGameCubo04;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TSoftClassPtr<UObject> pExGamesBandeira01;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TSoftClassPtr<UObject> pExGamesBandeira02;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TSoftClassPtr<UObject> pExGamesBandeira03;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TSoftClassPtr<UObject> pExGamesBandeira04;

    //Armazena o score
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 pExGameScore;

    //Armazena o estado do jogo
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        ExGame_EstadoJogo pExGame_Estado;

};


/**
 * 
 */
UCLASS()
class EXGAMES_API UExGamesLib : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category =  "ExGame|Functions")
        static bool ExGameInit(UGameInstance* pGameInstance) {
            pExGame_GameInstance = pGameInstance;

            UWorld* pWorld = pGameInstance->GetWorld();

            pExGamesSpawnLocation = FVector(0, 0, 30);

            if (pWorld->IsValidLowLevel()) { 
                AActor* Player = (AActor*)pWorld->SpawnActor(AExGamesCharacterBase::StaticClass(), &pExGamesSpawnLocation);
                
                return false;

                //UGameplayStatics::GetAllActorsOfClass(pWorld)
            }

            return true;
    }

    static UGameInstance* pExGame_GameInstance;
    static FVector pExGamesSpawnLocation;
};
