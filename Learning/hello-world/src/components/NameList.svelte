<script>
    const names= [
        {
            firstName:'Bruce',
            lastname:'Wayne'
        },
        {
            firstName:'Clark',
            lastname:'Kent'
        },
        {
            firstName:'Princess',
            lastname:'Diana'
        }
    ]
</script>

{#each names as name (name)}
    <slot name='hero' firstName={name.firstName} lastName={name.lastname} />
{/each}


