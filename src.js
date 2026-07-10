function fetchdata(){
    console.log("Data fetched");
}
const window=globalThis;
window.addEventListener('scroll',()=>{
    if(window.scrollY+window.innerHeight>=document.body.offsetHeight){
        fetchdata();
    }
})