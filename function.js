// Smooth scrolling effect for navigation links
document.querySelectorAll('nav a').forEach(anchor => {
    anchor.addEventListener('click', function(e) {
        e.preventDefault();
        
        const targetId = this.getAttribute('href').substring(1); // Get target section ID
        const targetElement = document.getElementById(targetId); // Get the target element by ID
        
        // Scroll smoothly to the target section, with an offset to avoid overlap with fixed headers
        window.scrollTo({
            top: targetElement.offsetTop - 60,  // Adjusted to prevent overlap if header is fixed
            behavior: 'smooth'  // Enable smooth scrolling
        });
    });
});
