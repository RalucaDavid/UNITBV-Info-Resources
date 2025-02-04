using UnityEngine;

public class Chest : MonoBehaviour
{
    private Animator _animator;
    private ParticleSystem _particleSystem;
    private AudioSource _audioSource;

    [SerializeField] private AudioClip _OpenChestSound;
    [SerializeField] private AudioClip _GoldSound;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        _animator = GetComponent<Animator>();
        _particleSystem = GetComponent<ParticleSystem>();
        _audioSource = GetComponent<AudioSource>();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void OpenChest()
    {
        // The aniamtor plays the animation with the given name.
        _animator.Play("Open");
    }

    public void PlayOpenChestSound()
    {
        // Assign the desired audio clip and play it.
        _audioSource.clip = _OpenChestSound;
        _audioSource.Play();
    }

    public void TriggerCoinParticles()
    {
        // Start the particle system.
        _particleSystem.Play();

        // Assign the desired audio clip and play it.
        _audioSource.clip = _GoldSound;
        _audioSource.Play();
    }
}
