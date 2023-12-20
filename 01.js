const { jsPDF } = require("jspdf");

var employees = [
  
{
  "name": "Ishan Awasthi",
  "email": "awasthishrey11@gmail.com",
  "phone": "9808243629",
  "skills": [
    "#PHP", "#JavaScript", "#CSS", "#Codeigniter", "#Laravel", "#VueJS", "#NodeJS", "#ReactJS"
  ],
  "education": [
    {
      "school_name": "University of Portsmouth",
      "logo": "portsmouth.jpg",
      "level": "Bachelor's Degree",
      "title": "Bsc Honors In Computing",
      "year": "2008-2011"
    },
    {
      "school_name": "Informatics Academy Kathmandu",
      "logo": "informatis.jpg",
      "level": "Diploma",
      "title": "Bsc Honors In Computing ",
      "year": "2008-2010"
    }
  ],
  "experiences": [
    {
      "company": "GitHub",
      "company_logo": "github.png",
      "postion": "Senior Developer",
      "duties": [
        "Research And Development",
        "Frontend Development"
      ]
    },
    {
      "company": "HyperLoop",
      "company_logo": "hyperLoop.png",
      "postion": "Lead Developer",
      "work_year": "2016 - 2017",
      "duties": [
        "Research And Development",
        "Rest API Service Development",
        "Develop And Support Laravel Powered System"
      ]
    }
  ]
}
// Your employee data...
];

var aboutMeText =
  "I am a passionate and experienced developer with expertise in various technologies.\n I am a really hardworking person and would like to collaborate more on this work so that I could upskill my work and collaborate with the team.\nSometimes I get distracted due to mobiles and computer games.";

var doc = new jsPDF();
var pageHeight = doc.internal.pageSize.height;
var middleOfPage = pageHeight / 2;
var yPos = 10;
var printedAboutMe = false;

// Function to print name, email, and phone at top center
function printContactInfo(name, email, phone) {
  doc.setFontSize(12); // Set font size for the name, email, and phone number section
  doc.setFont("Times", "normal");
  doc.text(105, yPos, `Name: ${name}`, { align: "center", width: 210 });
  doc.text(105, yPos + 10, `Email: ${email}`, { align: "center", width: 210 });
  doc.text(105, yPos + 20, `Phone: ${phone}`, { align: "center", width: 210 });
}

employees.forEach(function (employee) {
  printContactInfo(employee.name, employee.email, employee.phone);

  if (!printedAboutMe && aboutMeText && (employee.skills || employee.education.length > 0)) {
    yPos += 40; 
    doc.setFont("Times", "bold");
    doc.text(2, yPos, "About Me:", { align: "left" });
    doc.setFont("Times", "normal");
    yPos += 5;
    doc.setFontSize(10);
    doc.text(2, yPos, aboutMeText, { align: "left" });
    yPos += doc.getTextDimensions(aboutMeText, { fontSize: 10 }).h + 15; // Adjust the yPos based on the height of the text
    printedAboutMe = true;
  }

  if (employee.skills) {
  
    if (yPos + 30 > pageHeight) {
      doc.addPage();
      yPos = 10;
      printContactInfo(employee.name, employee.email, employee.phone);
    }

    doc.setFont("Times", "bold");
    doc.text(2, yPos, "Skills:", { align: "left" });
    doc.setFont("Times", "normal");
    yPos += 5;
    doc.setFontSize(10);
    doc.text(2, yPos, employee.skills.join(', '), { align: "left" });
    yPos += 15;
  }

  if (employee.experiences) {
    if (yPos + 40 > pageHeight) {
      doc.addPage();
      yPos = 10;
      printContactInfo(employee.name, employee.email, employee.phone);
    }

    doc.setFont("Times", "bold");
    doc.text(2, yPos, "Experience:", { align: "left" });
    doc.setFont("Times", "normal");

    employee.experiences.forEach((experience) => {
      const experienceText = `Company: ${experience.company}\nPosition: ${experience.position}\nWork Year: ${experience.work_year || 'N/A'}\nDuties: ${experience.duties.join(', ')}`;
      yPos += 5;
      doc.setFontSize(10);
      doc.text(2, yPos, experienceText, { align: "left" });
      yPos += doc.getTextDimensions(experienceText, { fontSize: 10 }).h + 15;
    });

    yPos += 10;
  }

  if (employee.education && employee.education.length > 0) {
    if (yPos + 40 > pageHeight) {
      doc.addPage();
      yPos = 10;
      printContactInfo(employee.name, employee.email, employee.phone);
    }

    doc.setFont("Times", "bold");
    doc.text(2, yPos, "Education:", { align: "left" });
    doc.setFont("Times", "normal");

    employee.education.forEach((edu) => {
      const educationText = `School name: ${edu.school_name}\nLevel: ${edu.level}\nTitle: ${edu.title}\nYear: ${edu.year}`;
      yPos += 5;
      doc.setFontSize(10);
      doc.text(2, yPos, educationText, { align: "left" });
      yPos += doc.getTextDimensions(educationText, { fontSize: 10 }).h + 15;
    });
  }
});

doc.save("Test.pdf");
