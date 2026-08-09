import './AboutSection.css';

function AboutSection() {
  return (
    <section id='about' className='about-section'>
      <div className='about-wrapper container'>
        <div className='about-image'>
          <img src='/Photo.jpeg' alt='Inchara Hugar' />
        </div>
        <div className='about-copy'>
          <h1>About Me</h1>
          <p>
           Hi! I'm Inchara, an undergraduate student pursuing a BTech in Computer Science, currently interning in web development. I enjoy building clean, functional interfaces and learning new tools along the way.
          </p>
        </div>
      </div>
    </section>
  );
}

export default AboutSection;
