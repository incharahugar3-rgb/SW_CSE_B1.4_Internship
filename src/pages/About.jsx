import './AboutPage.css';
import AboutSection from '../components/AboutSection/AboutSection';
import GitHubStats from '../components/GitHubStats/GitHubStats';
import SkillCard from '../components/SkillCard/SkillCard';

const SKILLS = [
  { name: 'React', level: 'Intermediate', icon: '⚛️' },
  { name: 'CSS3', level: 'Intermediate', icon: '🎨' },
  { name: 'HTML5', level: 'Intermediate', icon: '🌐' },
  { name: 'Git/GitHub', level: 'Intermediate', icon: '🔧' },
  { name: 'JavaScript', level: 'Intermediate', icon: '⚡' },
];

function About() {
  return (
    <div className='about-page container'>
      <AboutSection />

      <section id='skills' className='skills-section' style={{ marginTop: '40px' }}>
        <h2>Skills</h2>
        <div style={{ display: 'grid', gridTemplateColumns: 'repeat(auto-fit, minmax(200px, 1fr))', gap: '20px' }}>
          {SKILLS.map(s => <SkillCard key={s.name} name={s.name} level={s.level} icon={s.icon} />)}
        </div>
      </section>

      <section style={{ marginTop: '40px' }}>
        <h2>GitHub Activity</h2>
        <GitHubStats username='Incharahugar3-rgb' />
      </section>
    </div>
  );
}
export default About;