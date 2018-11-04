#include "MusicManager.h"

void MusicManager::Load(Music& m)
{
	m.Load();
}

void MusicManager::Unload(Music& m)
{
	m.Unload();
}

void MusicManager::Play(Music& m)
{
	m.Play();
}

void MusicManager::Pause(Music& m)
{
	m.Pause();
}

void MusicManager::Stop(Music& m)
{
	m.Stop();
}

void MusicManager::Resume(Music& m)
{
	m.Resume();
}

void MusicManager::Setvolume(Music& m, int v)
{
	m.SetVolume(v);
}