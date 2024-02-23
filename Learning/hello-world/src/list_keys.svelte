<script>
  import { shuffle } from "lodash";
  let names = ["Bruce", "Clark", "Diana", "Barry"];
  const shuffleNames = () => {
    names = shuffle(names);
  };
</script>

<style>
  main {
    font-family: sans-serif;
    text-align: center;
  }
</style>

<main>
  {#each names as name (name)}  <!-- The key is used to tie the last name with the first name-->
    <h2>{name}</h2>
    <input placeholder="Last name" />
  {/each}
  <div>
   <button on:click={shuffleNames}>Shuffle!</button>
  </div>
</main>