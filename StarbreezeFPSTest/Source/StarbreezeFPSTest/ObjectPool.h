// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Decal.h"
#include <list>
#include "ObjectPool.generated.h"


UCLASS()
class STARBREEZEFPSTEST_API AObjectPool : public AActor
{
	GENERATED_BODY()

public:

	/** Object class to pool */
	UPROPERTY( EditDefaultsOnly, Category = Content )
		TSubclassOf<ADecal> m_cDecalClass;

	/** size of pool */
	UPROPERTY( EditInstanceOnly, Category = Content )
		int m_iSize;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	std::list<UObject*> m_lLiveList;  //currently active/used objects in the pool
	std::list<UObject*> m_lDeadList;  //currently inactive objects in the pool. They can be recycled.

public:
	// Called every frame
	virtual void Tick( float DeltaTime ) override;
	ADecal* GetObjFromPool();
	void	ReturnToPool( ADecal* );

	FORCEINLINE static AObjectPool* GetInstance()
	{
		return m_pInstance;
	}

private:
	void ToggleInstanceEnabled( ADecal* Instance, bool IsEnabled );

	// Sets default values for this actor's properties
	AObjectPool();

	static  AObjectPool* m_pInstance;
};

